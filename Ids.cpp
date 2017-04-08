//
// Created by tg on 07/04/17.
//

#include "Ids.h"
Ids::Ids(std::string archivo, GestorMonitor &gest) : gestor(gest),
                                                  sniffer(archivo){}
void Ids::run() {
  bool eof = false;
  bool nuevoP= false;
  Paquete paqueteNuevo;
  /*while (!eof) {
    do{
      Paquete paquete = sniffer.sniff(&eof);
      if(!eof){
        gestor.agregar(paquete);
        paqueteNuevo = gestor.hayNuevoPaquete(&nuevoP);
      }
    }while (!eof && !nuevoP);
    if (!eof) {
      std::cout << "ID:" << paqueteNuevo.getId() << std::endl;
      std::cout << "Long:" << paqueteNuevo.getLongitudDatos() << std::endl;
      char data[MAX_LEN_DATA];
      paqueteNuevo.getData(data);
      for (int i = 0; i < paqueteNuevo.getLongitudDatos(); i++) {
        std::cout << data[i];
      }
      std::cout << std::endl;
    }*/
  while(!sniffer.termino()){
    while(!sniffer.termino() && gestor.siHayPaqueteNuevoObtener(&paqueteNuevo)){
      Paquete paquete = sniffer.sniff();
      gestor.agregar(paquete);
    }
    //AnalizarPaquetenuevo
    std::cout << "ID:" << paqueteNuevo.getPaqId() << std::endl;
    std::cout << "Long:" << paqueteNuevo.getLongitudDatos() << std::endl;
    char data[MAX_LEN_DATA];
    paqueteNuevo.getData(data);
    for (int i = 0; i < paqueteNuevo.getLongitudDatos(); i++) {
      std::cout << data[i];
    }
    std::cout << std::endl;
  }
}

