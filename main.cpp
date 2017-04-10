#include <iostream>
#include <vector>
#include <algorithm>
#include "Paquete.h"
#include "Sniffer.h"
#include "Gestor.h"
#include "Ids.h"
#include "Detector.h"
#include "Regla.h"
int main() {
  /*GestorMonitor gestor;
  Ids ids("packets.cap", gestor);
  ids.run();*/
  Sniffer sniffer("one.cap");
  Paquete paq;
  paq = sniffer.sniff();
  Regla* regla = Regla::crearRegla("1 2 0 all hola");
  bool aux = regla->aplicar(paq);
  return 0;
}