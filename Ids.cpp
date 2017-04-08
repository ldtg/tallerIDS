//
// Created by tg on 07/04/17.
//

#include "Ids.h"
Ids::Ids(std::string archivo, Ensamblador &ens) : ensamblador(ens),
                                                  sniffer(archivo){}
void Ids::run() {
  bool eof = false;
  bool nuevoP= false;
  Paquete paqueteNuevo;
  while (!eof) {
    do{
      Paquete paquete = sniffer.sniff(&eof);
      if(!eof){
        ensamblador.agregar(paquete);
        paqueteNuevo = ensamblador.nuevoPaquete(&nuevoP);
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
    }

    //if(!eof)
    //Analizar;
  }
}

