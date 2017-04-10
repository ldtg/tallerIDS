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
  std::vector<char> data;
  unsigned short getDosBytes(std::vector<char> header, int byteInicio);
  unsigned int getCuatroBytes(std::vector<char> header, int byteInicio);
  void toZero();
  std::vector<char> ensamblarDatos(Paquete &pkg);
  void ensamblarUltimo(Paquete &paquete);
  bool paqueteEstaAdentroThis(Paquete &paquete);
  bool esIdIgual(Paquete &paquete);
  bool tieneMismoInicioOfinal(Paquete &paquete);
  bool ensambleValido(Paquete &paquete);
  unsigned short longMinimo(Paquete &pkg);
 public:
  Paquete();
  Paquete(std::vector<char> header);
  int getLongitudDatos();
  Id getId();
  unsigned int getSrc();
  unsigned int getDst();
  unsigned short getPaqId();
  int getOffset();
  void setData( std::vector<char> data, size_t dataL);
  std::vector<char> getData();
  bool estaCompleto();
  void ensamblar(Paquete &paqueteNuevo);
  ~Paquete();

};

#endif //TP2_APP_PAQUETE_H
