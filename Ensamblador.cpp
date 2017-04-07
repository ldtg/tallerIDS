//
// Created by tg on 07/04/17.
//

#include "Ensamblador.h"
Ensamblador::Ensamblador() {

}
void Ensamblador::agregar(Paquete paquete) {
  Id id(paquete);
  if (this->paquetes.agregarPaquete(paquete)){
    Paquete aux = this->paquetes.get_si_completo(id);
    stackPaqsCompletos.push(aux);
  }
}
Paquete Ensamblador::nuevoPaquete(bool *nuevoP) {
  return stackPaqsCompletos.popSiNoVacio(nuevoP);
}
