//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_ENSAMBLADOR_H
#define TP2_APP_ENSAMBLADOR_H

#include "PaqsCompletosMon.h"
#include "PaquetesMonitor.h"
class Ensamblador {
 private:
  PaqsCompletosMon stackPaqsCompletos;
  PaquetesMonitor paquetes;
 public:
  Ensamblador();
  void agregar(Paquete paquete);
  Paquete nuevoPaquete(bool *np);
};

#endif //TP2_APP_ENSAMBLADOR_H
