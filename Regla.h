//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_REGLA_H
#define TP2_APP_REGLA_H
#include <string>
#include "Paquete.h"

class Regla {
 protected:
  unsigned int src;
  unsigned int dst;
  unsigned int threshold;
  std::string keyword;
  std::vector<std::string> words;
  bool dstAplica(unsigned int src);
  bool srcAplica(unsigned int src);
  bool SDTAplica(Paquete &paquete);
 public:
  Regla(unsigned int src, unsigned int dst, unsigned int threshold,
        std::vector<std::string> words);
  virtual bool aplicar(Paquete &paquete) = 0;
};

#endif //TP2_APP_REGLA_H
