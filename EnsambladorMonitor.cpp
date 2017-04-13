#include "EnsambladorMonitor.h"
#include "Lock.h"
Paquete EnsambladorMonitor::agregar(Paquete paquete) {
  Lock lock(mutex);
  Paquete paqueteAux;
  paqueteAux = this->ensamblador.agregar(paquete);
  return paqueteAux;
}
EnsambladorMonitor::EnsambladorMonitor(std::mutex &mutex) : mutex(mutex) {}
EnsambladorMonitor::~EnsambladorMonitor() {
}
