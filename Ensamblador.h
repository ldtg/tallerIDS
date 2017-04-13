//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_ENSAMBLADOR_H
#define TP2_APP_ENSAMBLADOR_H

#include <map>
#include <vector>
#include "Paquete.h"
#include "Id.h"
class Ensamblador {
 private:
  std::vector<Paquete> paquetes;
  bool esta(Paquete paquete);
  size_t posicion(Paquete paquete);
 public:
  Ensamblador();
  Paquete agregar(Paquete paqueteNuevo);
  Ensamblador(const Ensamblador&) = delete;
  Ensamblador& operator=(const Ensamblador&) = delete;
  ~Ensamblador();
};

#endif //TP2_APP_ENSAMBLADOR_H
