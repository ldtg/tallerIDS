#include <iostream>
#include "Paquete.h"
#include "Sniffer.h"
#include "Ensamblador.h"
#include "Ids.h"
int main() {
  std::cout << std::endl;
  Ensamblador ensamblador;
  Ids ids("packets.cap",ensamblador);
  ids.run();
  return 0;
}