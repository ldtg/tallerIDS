//
// Created by tg on 08/04/17.
//

#include "GestorMonitor.h"
#include "Lock.h"
void GestorMonitor::agregar(Paquete &paquete) {
  Lock lock(mutexGestor);
  this->gestor.agregar(paquete);
}
bool GestorMonitor::siHayPaqueteNuevoObtener(Paquete *paquete) {
  Lock lock(mutexGestor);
  if(this->gestor.hayNuevoPaquete()){
    *paquete = this->gestor.obtenerSiguientePaqueteCompleto();
    return true;
  }
  return false;
}
