#include <mutex>
#include <algorithm>
#include <vector>
#include "Ensamblador.h"
#include "Lock.h"

Paquete Ensamblador::agregar(Paquete paqueteNuevo) {
  std::vector<Paquete>::iterator encontrado = std::find(paquetes.begin(),
                                                       paquetes.end
      (), paqueteNuevo);
  if (encontrado != paquetes.end()) {
    size_t pos = (size_t)std::distance(paquetes.begin(),encontrado);
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