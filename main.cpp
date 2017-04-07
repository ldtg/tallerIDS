#include <iostream>
#include "Paquete.h"
#include "Sniffer.h"
int main() {
  char header[] = "\x45\x00\x00\x18\x00\x00\x20\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x01\x00\x00\x00\x02";
  bool eof = false;

  Sniffer snf("packet_fragmented.cap");
  while (!eof){
    Paquete pkg = snf.sniff(&eof);

    if(!eof){
      std::cout << "Id:"<<pkg.getId() << std::endl;
      std::cout <<"Completo:"<< pkg.estaCompleto() << std::endl;
      std::cout << "Long:"<<pkg.getLongitudDatos() << std::endl;
      char data[pkg.getLongitudDatos()];
      pkg.getData(data);
      for(int i=0; i < pkg.getLongitudDatos(); i++){
        std::cout << data[i];
      }
      std::cout << std::endl;
    }

  }

  return 0;
}