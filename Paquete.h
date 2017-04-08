#ifndef TP2_APP_PAQUETE_H
#define TP2_APP_PAQUETE_H
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include "Id.h"
#define MAX_LEN_DATA 65535
#define HEADER_SIZE 20
class Paquete {
 private:
  Id id;
  unsigned short longitudDatos;
  unsigned short bytesFaltantes;
  unsigned short offset;
  bool hayMasFragmentos;
  bool completo;
  char data[MAX_LEN_DATA];
  unsigned short getDosBytes(char header[HEADER_SIZE], int byteInicio);
  unsigned int getCuatroBytes(char header[HEADER_SIZE], int byteInicio);
  void toZero();
  void ensamblarDatos(char ensamblada[MAX_LEN_DATA], Paquete &pkg);
  void ensamblarUltimo(Paquete &paquete,
                       unsigned short otroOffset,
                       unsigned short otroLongDatos,
                       unsigned short ultimoOffset);
  void ensamblarAdentro(Paquete &paquete,
                        unsigned short adentroOffset,
                        unsigned short adentroLongDatos,
                        unsigned short afueraOffset,
                        unsigned short afueraLongDatos);
  unsigned short longMinimo(unsigned short minOffset, Paquete &pkg);
 public:
  Paquete();
  Paquete(char header[HEADER_SIZE]);
  int getLongitudDatos();
  unsigned int getSrc();
  unsigned int getDst();
  unsigned short getPaqId();
  int getOffset();
  void setData(char data[MAX_LEN_DATA], int dataL);
  bool getData(char data[MAX_LEN_DATA]);
  bool estaCompleto();
  Id getId();
  void ensamblar(Paquete &paqueteNuevo);
  ~Paquete();

  /*Paquete &operator=(Paquete &&other) {
    this->paqid = other.paqid;
    this->longitudDatos = other.longitudDatos;
    this->bytesFaltantes = other.bytesFaltantes;
    this->offset = other.offset;
    this->src = other.src;
    this->dst = other.dst;
    this->hayMasFragmentos = other.hayMasFragmentos;
    this->completo = other.completo;
    this->data = std::move(other.data);
    return *this;
  }*/

  bool thisEstaAdentroPaquete(Paquete &paquete);
  bool paqueteEstaAdentroThis(Paquete &paquete);
  bool esIdIgual(Paquete &paquete);
  bool tieneMismoInicioOfinal(Paquete &paquete);
  bool ensambleValido(Paquete &paquete);
  unsigned short longMinimo(Paquete &pkg);
};

#endif //TP2_APP_PAQUETE_H
