//
// Created by tg on 07/04/17.
//

#include "Ids.h"
Ids::Ids(std::string archivo, GestorMonitor &gest) : gestor(gest),
                                                     sniffer(archivo) {}
void Ids::run() {
  Paquete paqueteNuevo;
  while (!sniffer.termino()) {
    while (!sniffer.termino()
        && !gestor.siHayPaqueteNuevoObtener(&paqueteNuevo)) {
      Paquete paquete = sniffer.sniff();
      gestor.agregar(paquete);
    }
    //AnalizarPaquetenuevo
    if (!sniffer.termino()) {
      std::cout << "ID:" << paqueteNuevo.getPaqId() << std::endl;
      std::cout << "Long:" << paqueteNuevo.getLongitudDatos() << std::endl;
      std::vector<char> data;
      data = paqueteNuevo.getData();
      for (int i = 0; i < paqueteNuevo.getLongitudDatos(); i++) {
        std::cout << data[i];
      }
      std::cout << std::endl;
    }

  }
}

