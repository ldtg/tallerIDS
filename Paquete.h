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
  unsigned short getDosBytes(const std::vector<char> &header, int byteInicio)
  const;
  unsigned int getCuatroBytes(const std::vector<char> &header, int
  byteInicio) const;
  void toZero();
  std::vector<char> ensamblarDatos(const Paquete &pkg);
  void ensamblarUltimo(const Paquete &paquete);
  bool paqueteEstaAdentroThis(const Paquete &paquete) const;
  bool esIdIgual(const Paquete &paquete) const;
  bool ensambleValido(const Paquete &paquete) const;
  unsigned short longMinimo(const Paquete &pkg) const;

 public:
  Paquete();
  explicit Paquete(const std::vector<char> &header);
  unsigned short getLongitudDatos() const;
  Id getId() const;
  unsigned int getSrc() const;
  unsigned int getDst() const;
  void setData(const std::vector<char> &data, size_t dataL);
  std::vector<char> getData() const;
  bool estaCompleto() const;
  void ensamblar(const Paquete &paqueteNuevo);
  bool estaVacio() const;

  Paquete(const Paquete& paq);
  Paquete& operator=(const Paquete& paq);
  bool operator==(const Paquete& paq);
  ~Paquete();
};
#endif //TP2_APP_PAQUETE_H
