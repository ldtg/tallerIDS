#ifndef TP2_APP_DETECTOR_H
#define TP2_APP_DETECTOR_H

#include "Regla.h"
#include <string>
#include <vector>
class Detector {
 private:
  std::vector<Regla *> reglas;
  std::vector<std::string> llenarTokens(std::ifstream *inFile);
  std::vector<Paquete> paquetesProcesados;
  void imprimirAlerta(long pos,const Paquete &paquete);
  bool fueProcesado(const Paquete &paquete);
 public:
  explicit Detector(std::string configFile);
  void aplicar(const Paquete &paquete);
  ~Detector();
};

#endif //TP2_APP_DETECTOR_H
