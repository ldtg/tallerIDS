//
// Created by tg on 08/04/17.
//

#ifndef TP2_APP_GESTORMONITOR_H
#define TP2_APP_GESTORMONITOR_H

#include <mutex>
#include "Ensamblador.h"
class EnsambladorMonitor {
 private:
  Ensamblador ensamblador;
  std::mutex &mutex;
 public:
  explicit EnsambladorMonitor(std::mutex &mutex);
  Paquete agregar(Paquete paquete);
  EnsambladorMonitor(const EnsambladorMonitor &) = delete;
  EnsambladorMonitor &operator=(const EnsambladorMonitor &) = delete;
  //Paquete siHayPaqueteNuevoObtener();
  ~EnsambladorMonitor();
};

#endif //TP2_APP_GESTORMONITOR_H
