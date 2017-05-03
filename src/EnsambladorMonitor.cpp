#include "EnsambladorMonitor.h"
#include "Lock.h"
EnsambladorMonitor::EnsambladorMonitor() {}

Paquete EnsambladorMonitor::agregar(const Paquete &paquete) {
  Lock lock(mutex);
  Paquete paqueteAux;
  paqueteAux = this->ensamblador.agregar(paquete);
  return paqueteAux;
}

EnsambladorMonitor::~EnsambladorMonitor() {}
