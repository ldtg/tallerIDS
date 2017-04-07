//
// Created by tg on 07/04/17.
//

#include "PaqsCompletosMon.h"
#include "Lock.h"
PaqsCompletosMon::PaqsCompletosMon() {

}
void PaqsCompletosMon::push(Paquete &paquete) {
  Lock lockStack(mutexStack);
  paquetesCompletos.push(paquete);
}
Paquete PaqsCompletosMon::popSiNoVacio(bool *nuevo) {
  Lock lockStack(mutexStack);
  Paquete paquete;
  *nuevo = false;
  if (!paquetesCompletos.empty()) {
    paquete = paquetesCompletos.top();//TODO movimiento
    paquetesCompletos.pop();
    *nuevo = true;
    return paquete;
  }
  *nuevo = false;
  return paquete;
}
