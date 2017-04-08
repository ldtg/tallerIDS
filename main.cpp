#include <iostream>
#include "Paquete.h"
#include "Sniffer.h"
#include "Gestor.h"
#include "Ids.h"
#include "Detector.h"
#include "Regla.h"
int main() {
/*  Gestor gestor;
  Ids ids("packets.cap",gestor);
  ids.run();*/
  Paquete paquete;
  Sniffer sniffer("one.cap");
  while(!sniffer.termino()){
    paquete = sniffer.sniff();
    std::cout << "ID:" << paquete.getPaqId() << std::endl;
    std::cout << "Long:" << paquete.getLongitudDatos() << std::endl;
    char data[MAX_LEN_DATA];
    paquete.getData(data);
    for (int i = 0; i < paquete.getLongitudDatos(); i++) {
      std::cout << data[i];
    }
    std::cout << std::endl;
  }
  return 0;
}