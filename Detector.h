//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_DETECTOR_H
#define TP2_APP_DETECTOR_H

#include "Regla.h"
class Detector {
 private:
  std::vector<Regla*> reglas;
  std::vector<std::string> llenarTokens(std::string regla);
 public:
  Detector(std::string configFile);
  ~Detector();
  void aplicar(Paquete &paquete);
};

#endif //TP2_APP_DETECTOR_H
