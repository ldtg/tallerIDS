//
// Created by tg on 08/04/17.
//

#ifndef TP2_APP_GESTORMONITOR_H
#define TP2_APP_GESTORMONITOR_H

#include <mutex>
#include "Gestor.h"
class GestorMonitor {
 private:
  Gestor gestor;
  std::mutex mutexGestor;
 public:
  void agregar(Paquete &paquete);
  //Paquete siHayPaqueteNuevoObtener();
  bool siHayPaqueteNuevoObtener(Paquete *paquete);
};

#endif //TP2_APP_GESTORMONITOR_H
