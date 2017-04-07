//
// Created by tg on 07/04/17.
//

#include "PaquetesMonitor.h"
#include "Lock.h"
PaquetesMonitor::PaquetesMonitor() {

}

bool PaquetesMonitor::agregarPaquete(Paquete paqueteNuevo) {
  Lock lock(mutexMap);
  Id newPaqId(paqueteNuevo);
  if (paquetes.count(newPaqId) == 1) {
    Paquete paqueteActual = paquetes.at(newPaqId);
    if (paqueteActual.estaCompleto()) {
      return false;
    }
    paqueteActual.ensamblar(paqueteNuevo);
    paquetes[newPaqId] = paqueteActual;
    return paqueteActual.estaCompleto();
  } else {
    paquetes[newPaqId] = paqueteNuevo;
    return paqueteNuevo.estaCompleto();
  }
}
Paquete PaquetesMonitor::get_si_completo(Id id) {
  Paquete aux;
  if (paquetes.count(id) == 1){
    aux = paquetes.at(id);
    if(aux.estaCompleto())
      return aux;
  }

  return aux;
}
