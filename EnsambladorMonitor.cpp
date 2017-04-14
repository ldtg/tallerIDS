#include "EnsambladorMonitor.h"
#include "Lock.h"
Paquete EnsambladorMonitor::agregar(const Paquete& paquete) {
  Lock lock(mutex);
  Paquete paqueteAux;
  paqueteAux = this->ensamblador.agregar(paquete);
  return paqueteAux;
}
EnsambladorMonitor::EnsambladorMonitor(){}
EnsambladorMonitor::~EnsambladorMonitor() {
}
