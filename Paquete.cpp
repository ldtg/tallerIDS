#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include "Paquete.h"
Paquete::Paquete() {
  this->toZero();
}
Paquete::Paquete(const std::vector<char> &header) {
  unsigned short paqid = getDosBytes(header, 4);
  this->longitudDatos = (unsigned short) (getDosBytes(header, 2) - 20);
  this->hayMasFragmentos = (bool) ((header[6] & 32) >> 5);
  this->offset = (unsigned short) (getDosBytes(header, 6) & 8191); // solo los
  this->src = getCuatroBytes(header, 12);      //primeros 13 bytes
  this->dst = getCuatroBytes(header, 16);
  this->id = IdPaquete(this->src, this->dst, paqid);

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

void Paquete::ensamblar(const Paquete &paqueteNuevo) {
  if (ensambleValido(paqueteNuevo)) {
    std::vector<char> dataEnsamblada = ensamblarDatos(paqueteNuevo);

    unsigned short minOffset = std::min(this->offset, paqueteNuevo.offset);
    unsigned short maxOffset = std::max(this->offset, paqueteNuevo.offset);
    unsigned short longDatosMinimo = longMinimo(paqueteNuevo);

    if (!this->hayMasFragmentos || !paqueteNuevo.hayMasFragmentos) {//alguno
      ensamblarUltimo(paqueteNuevo);                          // es el ultimo
    } else if (paqueteEstaAdentroThis(paqueteNuevo)) {// __[T[PN]T]__
      this->bytesFaltantes -= paqueteNuevo.longitudDatos;
    } else {                  //Paquetes separados __[T]__[PN]__
      this->bytesFaltantes += (maxOffset - (longDatosMinimo + minOffset));
      this->longitudDatos += paqueteNuevo.longitudDatos + this->bytesFaltantes;
      this->offset = minOffset;
    }
    this->setData(dataEnsamblada, this->longitudDatos);
  }
}

unsigned int Paquete::getSrc() const {
  return this->src;
}

unsigned int Paquete::getDst() const {
  return this->dst;
}

unsigned short Paquete::getLongitudDatos() const {
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

IdPaquete Paquete::getId() const {
  return this->id;
}

Paquete::~Paquete() {
  this->toZero();
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
  unsigned int aux;
  aux = ((unsigned int) header[byteInicio] & (255)) << 24;
  aux += ((unsigned int) header[byteInicio + 1] & (255)) << 16;
  aux += ((unsigned int) header[byteInicio + 2] & (255)) << 8;
  aux += (unsigned int) header[byteInicio + 3] & (255);
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
  std::copy_n(this->data.begin(), this->longitudDatos, ensamblada.begin()
      + this->offset);
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

bool Paquete::ensambleValido(const Paquete &paquete) const {
  return !this->completo && !paquete.completo && esIdIgual(paquete);
}

bool Paquete::estaVacio() const {
  return this->longitudDatos == 0;
}

bool Paquete::operator==(const Paquete &paq) const {
  return paq.getId() == this->getId();
}

