#include <iostream>
#include "Paquete.h"
#include "Sniffer.h"
#include "Ensamblador.h"
#include "Ids.h"
#include "Detector.h"
#include "Regla.h"
int main() {
/*  Ensamblador ensamblador;
  Ids ids("packets.cap",ensamblador);
  ids.run();*/
  Regla regla("Hola como estas");
  return 0;
}