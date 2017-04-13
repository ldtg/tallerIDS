//
// Created by tg on 06/04/17.
//

#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include "Paquete.h"
Paquete::Paquete() {
  this->toZero();
}
Paquete::Paquete(const std::vector<char> &header) {
  unsigned int src, dst;
  unsigned short paqid;
  paqid = getDosBytes(header, 4);
  this->longitudDatos = (unsigned short) (getDosBytes(header, 2) - 20);
  this->hayMasFragmentos = (bool) ((header[6] & 32) >> 5);
  this->offset = (unsigned short) (getDosBytes(header, 6) & 8191); // solo los
  src = getCuatroBytes(header, 12);                   //primeros 13 bytes
  dst = getCuatroBytes(header, 16);
  this->id = Id(src, dst, paqid);

  if (!this->hayMasFragmentos && this->offset == 0) {
    this->completo = true;
    this->bytesFaltantes = 0;
  } else {
    this->completo = false;
    if (!this->hayMasFragmentos) {
      this->bytesFaltantes = this->offset;
    } else {
      this->bytesFaltantes = 0;
    }
  }
}

Paquete::~Paquete() {
  this->toZero();
}
int Paquete::getOffset() const {
  return this->offset;
}
unsigned int Paquete::getSrc() const {
  return this->id.getSrc();
}
unsigned int Paquete::getDst() const {
  return this->id.getDst();
}

int Paquete::getLongitudDatos() const {
  return this->longitudDatos;
}
void Paquete::setData(const std::vector<char> &data, size_t dataL) {
  this->data.resize(dataL);
  std::copy_n(data.begin(), dataL, this->data.begin());
}
std::vector<char> Paquete::getData() const {
  std::vector<char> data(this->longitudDatos);
  std::copy_n(this->data.begin(), this->longitudDatos, data.begin());
  return data;
}
bool Paquete::estaCompleto() const {
  return this->completo;
}
Id Paquete::getId() const {
  return this->id;
}
void Paquete::ensamblar(const Paquete &paqueteNuevo) {
  std::vector<char> dataEnsamblada;
  unsigned short minOffset, maxOffset, longDatosMinimo;

  if (ensambleValido(paqueteNuevo)) {
    dataEnsamblada = ensamblarDatos(paqueteNuevo);

    minOffset = std::min(this->offset, paqueteNuevo.offset);
    maxOffset = std::max(this->offset, paqueteNuevo.offset);
    longDatosMinimo = longMinimo(paqueteNuevo);

    if (!this->hayMasFragmentos || !paqueteNuevo.hayMasFragmentos) {//alguno
      ensamblarUltimo(paqueteNuevo);                          // es el ultimo
    } else if (paqueteEstaAdentroThis(paqueteNuevo)) {// __[_[P]_]__
      this->bytesFaltantes -= paqueteNuevo.longitudDatos;
    } else {                  //Paquetes separados __[P]__[P]__
      this->bytesFaltantes += (maxOffset - (longDatosMinimo + minOffset));
      this->longitudDatos += paqueteNuevo.longitudDatos + this->bytesFaltantes;
      this->offset = minOffset;
    }
    this->setData(dataEnsamblada, this->longitudDatos);
  }
}
unsigned short Paquete::getDosBytes(const std::vector<char> &header, int
byteInicio) const {
  unsigned short aux;
  unsigned char primerByte, segundoByte;
  primerByte = (unsigned char) header[byteInicio];
  segundoByte = (unsigned char) header[byteInicio + 1];
  //Recibidos en Big Endian
  aux = (unsigned short) primerByte << 8;//Envio el primer byte a la pos mas
  // significativa (segun el endianess del sistema)
  aux += (unsigned short) segundoByte;
  return aux;
}

unsigned int Paquete::getCuatroBytes(const std::vector<char> &header, int
byteInicio) const {
  unsigned int pb, sb, tb, cb, aux;
  pb = (unsigned int) header[byteInicio] & (255);
  sb = (unsigned int) header[byteInicio + 1] & (255);
  tb = (unsigned int) header[byteInicio + 2] & (255);
  cb = (unsigned int) header[byteInicio + 3] & (255);
  aux = pb << 24;
  aux += sb << 16;
  aux += tb << 8;
  aux += cb;
  return aux;
}
void Paquete::toZero() {
  this->longitudDatos = 0;
  this->bytesFaltantes = 0;
  this->offset = 0;
  this->hayMasFragmentos = false;
  this->completo = false;
  this->data.clear();
}
std::vector<char> Paquete::ensamblarDatos(const Paquete &pkg) {
  std::vector<char> ensamblada(MAX_LEN_DATA);
  std::copy_n(this->data.begin(), this->longitudDatos, ensamblada.begin
      () + this->offset);
  std::copy_n(pkg.data.begin(),
              pkg.longitudDatos,
              ensamblada.begin() + pkg.offset);
  return ensamblada;
}
unsigned short Paquete::longMinimo(const Paquete &pkg) const {
  unsigned short longDatosMinimo = 0;
  if (std::min(this->offset, pkg.offset) == this->offset)
    longDatosMinimo = this->longitudDatos;
  else
    longDatosMinimo = pkg.longitudDatos;
  return longDatosMinimo;
}

void Paquete::ensamblarUltimo(const Paquete &paquete) {
  unsigned short ultimoOffset, ultimoLongDatos, antesLongDatos;
  if (!paquete.hayMasFragmentos) {//Paquete es el ultimo
    ultimoOffset = paquete.offset;
    ultimoLongDatos = paquete.longitudDatos;
    antesLongDatos = this->longitudDatos;
  } else {
    antesLongDatos = paquete.longitudDatos;
    ultimoLongDatos = this->longitudDatos;
    ultimoOffset = this->offset;
  }
  this->hayMasFragmentos = false;

  if (paqueteEstaAdentroThis(paquete)) {
    this->bytesFaltantes += paquete.bytesFaltantes - paquete.longitudDatos;
  } else {
    this->bytesFaltantes += paquete.bytesFaltantes - antesLongDatos;
    this->longitudDatos = ultimoOffset + ultimoLongDatos;
    this->offset = 0;
  }
  this->completo = (this->bytesFaltantes == 0);
}

bool Paquete::paqueteEstaAdentroThis(const Paquete &paquete) const {
  return (paquete.offset > this->offset)
      && (paquete.offset < (this->offset +
          this->longitudDatos));
}

bool Paquete::esIdIgual(const Paquete &paquete) const {
  return this->id == paquete.id;
}

bool Paquete::tieneMismoInicioOfinal(const Paquete &paquete) const {
  return (this->offset == paquete.offset) || ((this->offset +
      this->longitudDatos) == (paquete.offset + paquete.longitudDatos));
}

bool Paquete::ensambleValido(const Paquete &paquete) const {
  return !this->completo && !paquete.completo && esIdIgual(paquete);
}

unsigned short Paquete::getPaqId() const {
  return this->id.getPaqId();
}
bool Paquete::estaVacio() const {
  return this->id.getDst() == 0 && this->id.getSrc() == 0;
}

Paquete::Paquete(const Paquete &paq) {
  this->id = paq.id;
  this->longitudDatos = paq.longitudDatos;
  this->bytesFaltantes = paq.bytesFaltantes;
  this->offset = paq.offset;
  this->hayMasFragmentos = paq.hayMasFragmentos;
  this->completo = paq.completo;
  this->data.resize(paq.data.size());
  std::copy(paq.data.begin(), paq.data.end(), this->data.begin());
}
Paquete &Paquete::operator=(const Paquete &paq) {
  this->id = paq.id;
  this->longitudDatos = paq.longitudDatos;
  this->bytesFaltantes = paq.bytesFaltantes;
  this->offset = paq.offset;
  this->hayMasFragmentos = paq.hayMasFragmentos;
  this->completo = paq.completo;
  this->data.resize(paq.data.size());
  std::copy(paq.data.begin(), paq.data.end(), this->data.begin());
  return *this;
}

