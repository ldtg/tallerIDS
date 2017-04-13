//
// Created by tg on 07/04/17.
//

#include <mutex>
#include "Ensamblador.h"
#include "Lock.h"

Paquete Ensamblador::agregar(Paquete paqueteNuevo) {
  if (esta(paqueteNuevo)) {
    size_t pos;
    pos = posicion(paqueteNuevo);
    Paquete paqueteActual = paquetes.at(pos);
    paqueteActual.ensamblar(paqueteNuevo);
    paquetes[pos] = paqueteActual;
    return paqueteActual;
  } else {
    paquetes.push_back(paqueteNuevo);
    return paqueteNuevo;
  }
}

Ensamblador::~Ensamblador() {
  paquetes.clear();
}
Ensamblador::Ensamblador() {
}
bool Ensamblador::esta(Paquete paquete) {
  for (auto &&item : paquetes) {
    if(paquete.getId() == item.getId())
      return true;
  }
  return false;
}
size_t Ensamblador::posicion(Paquete paquete) {
  for (size_t i = 0; i< paquetes.size(); i++) {
    if(paquetes[i].getId() == paquete.getId())
      return i;
  }
  return 0;
}
