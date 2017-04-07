#include <iostream>
#include "Paquete.h"
#include "Sniffer.h"
int main() {
  char header[] = "\x45\x00\x00\x18\x00\x00\x20\x00\x00\x00\x00\x00\x00\x00"
      "\x00\x01\x00\x00\x00\x02";
  bool eof = false;

  Sniffer snf("packet_fragmented.cap");
  Paquete pkg[7];
  int j = 0;
  while (!eof&&j<7){
    pkg[j]=snf.sniff(&eof);

    if(!eof){
      std::cout << j << std::endl;
      std::cout << "Id:"<<pkg[j].getId() << std::endl;
      std::cout <<"Completo:"<< pkg[j].estaCompleto() << std::endl;
      std::cout << "Long:"<<pkg[j].getLongitudDatos() << std::endl;
      std::cout << "Off:"<<pkg[j].getOffset() << std::endl;
      std::cout << "src:"<<pkg[j].getSrc() << std::endl;
      std::cout << "dst:"<<pkg[j].getDst() << std::endl;
      char data[pkg[j].getLongitudDatos()];
      pkg[j].getData(data);
      for(int i=0; i < pkg[j].getLongitudDatos(); i++){
        std::cout << data[i];
      }
      std::cout << std::endl;
    }
  j++;
  }
  pkg[0].ensamblar(pkg[6]);
  pkg[0].ensamblar(pkg[1]);
  pkg[0].ensamblar(pkg[2]);// error en el 6
  pkg[0].ensamblar(pkg[3]);
  std::cout << "Id:"<<pkg[0].getId() << std::endl;
  std::cout <<"Completo:"<< pkg[0].estaCompleto() << std::endl;
  std::cout << "Long:"<<pkg[0].getLongitudDatos() << std::endl;
  std::cout << "Off:"<<pkg[0].getOffset() << std::endl;
  char data[pkg[0].getLongitudDatos()];
  pkg[0].getData(data);
  for(int i=0; i < pkg[0].getLongitudDatos(); i++){
    std::cout << data[i];
  }
  std::cout << std::endl;

  return 0;
}