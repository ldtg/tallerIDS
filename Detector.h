#ifndef TP2_APP_DETECTOR_H
#define TP2_APP_DETECTOR_H

#include "Regla.h"
#include "ImpresionMonitor.h"
#include <string>
#include <vector>
class Detector {
 private:
  std::vector<Regla *> reglas;
  std::vector<std::string> llenarTokens(std::ifstream *inFile);
  ImpresionMonitor &impresion;
  std::vector<Paquete> paquetesProcesados;
  void imprimirAlerta(long pos,const Paquete &paquete);
  bool fueProcesado(const Paquete &paquete);
 public:
  Detector(std::string configFile, ImpresionMonitor &impresion);
  ~Detector();
  void aplicar(const Paquete &paquete);
};

#endif //TP2_APP_DETECTOR_H
