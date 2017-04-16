#ifndef TP2_APP_ENSAMBLADOR_H
#define TP2_APP_ENSAMBLADOR_H

#include <map>
#include <vector>
#include "Paquete.h"
#include "IdPaquete.h"
class Ensamblador {
 private:
  std::vector<Paquete> paquetes;
 public:
  Ensamblador();
  Paquete agregar(Paquete paqueteNuevo);
  ~Ensamblador();
};

#endif //TP2_APP_ENSAMBLADOR_H
