//
// Created by tg on 07/04/17.
//

#include "Gestor.h"

Gestor::Gestor() {

}
void Gestor::agregar(Paquete paqueteNuevo) {
  Paquete paqueteActual;
  if (paquetes.count(paqueteNuevo.getId()) == 1) {
    paqueteActual = paquetes.at(paqueteNuevo.getId());
    paqueteActual.ensamblar(paqueteNuevo);
    paquetes[paqueteNuevo.getId()] = paqueteActual;
    if (paqueteActual.estaCompleto()) {
      paquetesCompletos.push(paqueteActual);
    }
  } else {
    paquetes[paqueteNuevo.getId()] = paqueteNuevo;
    if (paqueteNuevo.estaCompleto()) {
      paquetesCompletos.push(paqueteNuevo);
    }
  }

}
bool Gestor::hayNuevoPaquete() {
  return !paquetesCompletos.empty();
}
Paquete Gestor::obtenerSiguientePaqueteCompleto() {
  Paquete aux;
  if(this->hayNuevoPaquete()){
    aux = paquetesCompletos.top();
    paquetesCompletos.pop();
  }
  return aux;
}
