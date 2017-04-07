//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_PAQUETESMONITOR_H
#define TP2_APP_PAQUETESMONITOR_H

#include <map>
#include <mutex>
#include "Paquete.h"
#include "Id.h"
class PaquetesMonitor {
 private:
  std::map<Id,Paquete> paquetes;
  std::mutex mutexMap;
 public:
  PaquetesMonitor();
  bool agregarPaquete(Paquete paqueteNuevo);
  Paquete get_si_completo(Id id);
};

#endif //TP2_APP_PAQUETESMONITOR_H
