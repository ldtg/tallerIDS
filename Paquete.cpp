//
// Created by tg on 06/04/17.
//

#include <netinet/in.h>
#include <cstring>
#include "Paquete.h"
Paquete::Paquete() {

}
Paquete::Paquete(char *header) {
  char aux[HEADER_SIZE];
  memcpy(aux,header,HEADER_SIZE);
  this->id = getDosBytes(header, 4);
  this->longitudDatos = (unsigned short) (getDosBytes(header, 2) - 20);
  this->mfFlag = (bool) ((header[6] & 32) >> 5);
  this->offset = (unsigned short) (getDosBytes(header, 6) & 8191); // solo los
  this->src = getCuatroBytes(header, 12);                   //primeros 13 bytes
  this->dst = getCuatroBytes(header, 16);
  if (!this->mfFlag && this->offset == 0) {
    this->completo = true;
    this->bytesFaltantes = 0;
  } else {
    this->completo = false;
    if (!this->mfFlag) {
      this->bytesFaltantes = this->offset;
    } else {
      this->bytesFaltantes = 0;
    }
  }
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
  unsigned int primerS, segundoS;
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
int Paquete::getLongitudDatos() {
  return this->longitudDatos;
}
bool Paquete::estaCompleto() {
  return this->completo;
}
int Paquete::setData(char *data, int dataL) {
  if (dataL < MAX_LEN_DATA)
    memcpy(this->data, data, (size_t)dataL);
  return 0;
}
bool Paquete::getData(char *data) {
  memcpy(data, this->data,(size_t)this->getLongitudDatos());
  return false;
}
unsigned short Paquete::getId() {
  return this->id;
}
void Paquete::ensamblar(Paquete pkg) {
  char dataEnsamblada[MAX_LEN_DATA] = "";
  int minOf, maxOf, longMin;
  if (!this->completo && !pkg.completo) {
    memcpy(dataEnsamblada + this->offset, this->data, this->longitudDatos);
    memcpy(dataEnsamblada + pkg.offset, pkg.data, pkg.longitudDatos);
    minOf = std::min(this->offset, pkg.offset);
    maxOf = std::max(this->offset, pkg.offset);
    if (minOf == this->offset)
      longMin = this->longitudDatos;
    else
      longMin = pkg.longitudDatos;
    if (!this->mfFlag && pkg.mfFlag) { //this es el ultimo
      this->bytesFaltantes = this->bytesFaltantes - pkg.longitudDatos + pkg
          .bytesFaltantes;
      if (this->bytesFaltantes == 0) {
        this->completo = true;
        this->offset = 0;
        this->longitudDatos += this->offset;
      } else{
        this->offset = minOf;
        this->longitudDatos +=
            pkg.longitudDatos + (maxOf - (longMin + minOf));
      }

    } else if (!pkg.mfFlag && this->mfFlag) { //pkg es el ultimo
      this->mfFlag = false;
      this->bytesFaltantes =
          pkg.bytesFaltantes - this->longitudDatos + this->bytesFaltantes;
      if (this->bytesFaltantes == 0) {
        this->completo = true;
        this->offset = 0;
      } else {
        this->offset = minOf;
      }
      this->longitudDatos +=
          pkg.longitudDatos + (maxOf - (longMin + minOf));
    } else if (pkg.mfFlag && this->mfFlag) { //Ninguno es el ultimo
      if ((this->offset > pkg.offset) && (this->offset < (pkg.offset + pkg
          .longitudDatos))) {
        //se metio this adentro de pkg
        this->bytesFaltantes =
            pkg.bytesFaltantes - this->longitudDatos + this->bytesFaltantes;
        this->longitudDatos = pkg.longitudDatos;
        this->offset = minOf;
      } else if ((pkg.offset > this->offset) && (pkg.offset < (this->offset +
          this->longitudDatos))) {
        //se metio el pkg adentro de this
        this->bytesFaltantes = this->bytesFaltantes - pkg.longitudDatos + pkg
            .bytesFaltantes;
      } else if (this->offset != pkg.offset) { //Si no son el mismo pkg
        this->bytesFaltantes = this->bytesFaltantes + pkg.bytesFaltantes
            + (maxOf - (longMin + minOf)); //Largo del Agujero

        this->longitudDatos += pkg.longitudDatos + this->bytesFaltantes;
        this->offset = minOf;
      }
    }
    this->setData(dataEnsamblada, this->longitudDatos);
  }
}
int Paquete::getOffset() {
  return this->offset;
}
unsigned int Paquete::getSrc() {
  return this->src;
}
unsigned int Paquete::getDst() {
  return this->dst;
}
Paquete::~Paquete() {

}
