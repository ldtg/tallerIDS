//
// Created by tg on 06/04/17.
//

#ifndef TP2_APP_PAQUETE_H
#define TP2_APP_PAQUETE_H
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#define MAX_LEN_DATA 65535
#define HEADER_SIZE 20
class Paquete {
 private:
  unsigned short id;
  unsigned short longitudDatos;
  unsigned short bytesFaltantes;
  unsigned short offset;
  unsigned int src;
  unsigned int dst;
  bool mfFlag;
 // bool enEnsamble;
  bool completo;
  char data[MAX_LEN_DATA];
  unsigned short getDosBytes(char header[HEADER_SIZE], int byteInicio);
  unsigned int getCuatroBytes(char header[HEADER_SIZE], int byteInicio);
 public:
  Paquete(char header[HEADER_SIZE]);
  int getLongitudDatos();
  int getOffset();
  int setData(char data[MAX_LEN_DATA], int dataL);
  bool getData(char data[MAX_LEN_DATA]);
  bool estaCompleto();
  unsigned short getId();
  void ensamblar(Paquete &pkg);
};

#endif //TP2_APP_PAQUETE_H
