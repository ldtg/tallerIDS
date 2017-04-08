//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_REGLA_H
#define TP2_APP_REGLA_H
#include <string>
#include "Paquete.h"

class Regla {
 private:
  unsigned int src;
  unsigned int dst;
  unsigned int threshold;
  std::string keyword;
  std::vector<std::string> words;
 public:
  Regla(std::string regla);
  void aplicar(Paquete paquete);
};

#endif //TP2_APP_REGLA_H
