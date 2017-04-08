//
// Created by tg on 06/04/17.
//

#include <netinet/in.h>
#include <cstring>
#include "Paquete.h"
Paquete::Paquete() {
  this->toZero();
}
Paquete::Paquete(char *header) {
  unsigned int src, dst;
  unsigned short paqid;
  memset(this->data, 0, MAX_LEN_DATA);
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
int Paquete::getOffset() {
  return this->offset;
}
unsigned int Paquete::getSrc() {
  return this->id.getSrc();
}
unsigned int Paquete::getDst() {
  return this->id.getDst();
}

int Paquete::getLongitudDatos() {
  return this->longitudDatos;
}
void Paquete::setData(char *data, int dataL) {
  if (dataL < MAX_LEN_DATA)
    memcpy(this->data, data, (size_t) dataL);
}
bool Paquete::getData(char *data) {
  memcpy(data, this->data, (size_t) this->getLongitudDatos());
  return false;
}
bool Paquete::estaCompleto() {
  return this->completo;
}
Id Paquete::getId() {
  return this->id;
}
void Paquete::ensamblar(Paquete &paqueteNuevo) {
  char dataEnsamblada[MAX_LEN_DATA] = "";
  unsigned short minOffset, maxOffset, longDatosMinimo;

  if (ensambleValido(paqueteNuevo)) {
    ensamblarDatos(dataEnsamblada, paqueteNuevo);

    minOffset = std::min(this->offset, paqueteNuevo.offset);
    maxOffset = std::max(this->offset, paqueteNuevo.offset);
    longDatosMinimo = longMinimo(paqueteNuevo);

    if (!this->hayMasFragmentos) { //this es el ultimo
      ensamblarUltimo(paqueteNuevo, paqueteNuevo.offset, paqueteNuevo
          .longitudDatos, this->offset);
    } else if (!paqueteNuevo.hayMasFragmentos) { //paqueteNuevo es el ultimo
      ensamblarUltimo(paqueteNuevo, this->offset, this->longitudDatos,
                      paqueteNuevo.offset);
    } else if (paqueteEstaAdentroThis(paqueteNuevo)) {
      this->bytesFaltantes -= paqueteNuevo.longitudDatos;
    } else {                  //Largo del Agujero
      this->bytesFaltantes += (maxOffset - (longDatosMinimo + minOffset));
      this->longitudDatos += paqueteNuevo.longitudDatos + this->bytesFaltantes;
      this->offset = minOffset;
    }
  }
  this->setData(dataEnsamblada, this->longitudDatos);

}
unsigned short Paquete::getDosBytes(char *header, int byteInicio) {
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

unsigned int Paquete::getCuatroBytes(char *header, int byteInicio) {
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
  memset(this->data, 0, MAX_LEN_DATA);

}
void Paquete::ensamblarDatos(char *ensamblada, Paquete &pkg) {
  memcpy(ensamblada + this->offset, this->data, this->longitudDatos);
  memcpy(ensamblada + pkg.offset, pkg.data, pkg.longitudDatos);
}
unsigned short Paquete::longMinimo(Paquete &pkg) {
  unsigned short longDatosMinimo = 0;
  if (std::min(this->offset, pkg.offset) == this->offset)
    longDatosMinimo = this->longitudDatos;
  else
    longDatosMinimo = pkg.longitudDatos;
  return longDatosMinimo;
}

void Paquete::ensamblarUltimo(Paquete &paquete, unsigned short otroOffset,
                              unsigned short otroLongDatos,
                              unsigned short ultimoOffset) {
  this->hayMasFragmentos = false;
  this->bytesFaltantes += paquete.bytesFaltantes - otroLongDatos;
  this->longitudDatos +=
      paquete.longitudDatos
          + (ultimoOffset - (otroLongDatos + otroOffset));
  this->completo = (this->bytesFaltantes == 0);
  this->offset = otroOffset;
}

bool Paquete::paqueteEstaAdentroThis(Paquete &paquete) {
  return (paquete.offset > this->offset)
      && (paquete.offset < (this->offset +
          this->longitudDatos));
}

bool Paquete::esIdIgual(Paquete &paquete) {
  return this->id == paquete.id;
}

bool Paquete::tieneMismoInicioOfinal(Paquete &paquete) {
  return (this->offset != paquete.offset) || ((this->offset +
      this->longitudDatos) != paquete.offset + paquete.longitudDatos);
}

bool Paquete::ensambleValido(Paquete &paquete) {
  return !this->completo && !paquete.completo && esIdIgual(paquete) &&
      !tieneMismoInicioOfinal(paquete);
}

unsigned short Paquete::getPaqId() {
  return this->id.getPaqId();
}

