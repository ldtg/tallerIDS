//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_DETECTOR_H
#define TP2_APP_DETECTOR_H

#include "Regla.h"
#include "ImpresionMonitor.h"
#include <string>
#include <vector>
class Detector {
 private:
  std::vector<Regla *> reglas;
  std::mutex m2;
  std::vector<std::string> llenarTokens(std::ifstream *inFile);
  ImpresionMonitor &impresion;
 public:
  Detector(std::string configFile, ImpresionMonitor &impresion);
  ~Detector();
  void aplicar(Paquete &paquete);
  void imprimirAlerta(long pos, Paquete &paquete);
};

#endif //TP2_APP_DETECTOR_H
