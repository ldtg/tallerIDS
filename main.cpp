#include <iostream>
#include "Paquete.h"
#include "Sniffer.h"
#include "Gestor.h"
#include "Ids.h"
#include "Detector.h"
#include "Regla.h"
int main() {
  GestorMonitor gestor;
  Ids ids("packets.cap",gestor);
  ids.run();
  return 0;
}