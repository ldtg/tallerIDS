#include "Ids.h"
#include <string>
#include <vector>
Ids::Ids(std::string archivo, EnsambladorMonitor &ensambladorMonitor,
         DetectorMonitor &dtk) : sniffer(archivo), ensambladorMonitor
    (ensambladorMonitor), detector(dtk) {}

void Ids::run() {
  while (!sniffer.termino()) {
    bool nuevoCompleto = false;
    Paquete paqueteNuevo;
    while (!sniffer.termino() && !nuevoCompleto) {
      paqueteNuevo = sniffer.sniff();
      if (paqueteNuevo.estaCompleto()) {
        nuevoCompleto = true;
      } else if (!paqueteNuevo.estaVacio()) {
        paqueteNuevo = ensambladorMonitor.agregar(paqueteNuevo);
        nuevoCompleto = paqueteNuevo.estaCompleto();
      }
    }
    if (paqueteNuevo.estaCompleto()) {
      detector.aplicar(paqueteNuevo);
    }
  }
}

Ids::~Ids() {}

