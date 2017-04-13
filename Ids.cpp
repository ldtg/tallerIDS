#include "Ids.h"
#include "Lock.h"
#include <string>
#include <vector>
Ids::Ids(std::string archivo, EnsambladorMonitor &ensambladorMonitor, Detector
&dtk)
    : ensambladorMonitor(ensambladorMonitor),
      sniffer(archivo), detector(dtk) {}

void Ids::run() {
  bool nuevoCompleto = false;
  while (!sniffer.termino()) {
    Paquete paqueteNuevo;

    while (!sniffer.termino() && !nuevoCompleto) {
      Paquete paquete = sniffer.sniff();
            if (paquete.estaCompleto()) {
        paqueteNuevo = paquete;
        nuevoCompleto = true;
      } else {
        if (!paquete.estaVacio()){
          paqueteNuevo = ensambladorMonitor.agregar(paquete);
        }
        if (paqueteNuevo.estaCompleto()) {
          nuevoCompleto = true;
        }
      }
    }
    nuevoCompleto = false;
    if(paqueteNuevo.estaCompleto()){
      detector.aplicar(paqueteNuevo);
    }
  }
}

