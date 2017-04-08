//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_ENSAMBLADOR_H
#define TP2_APP_ENSAMBLADOR_H

#include <map>
#include <stack>
#include "Paquete.h"
#include "Id.h"
//#include "PaqsCompletosMon.h"
//#include "PaquetesMonitor.h"
class Gestor {
 private:
  std::map<Id,Paquete> paquetes;
  std::stack<Paquete> paquetesCompletos;
  // PaqsCompletosMon stackPaqsCompletos;
  //PaquetesMonitor paquetes;
 public:
  Gestor();
  void agregar(Paquete paqueteNuevo);
  bool hayNuevoPaquete();
  Paquete obtenerSiguientePaqueteCompleto();
};

#endif //TP2_APP_ENSAMBLADOR_H
