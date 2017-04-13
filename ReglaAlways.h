//
// Created by tg on 09/04/17.
//

#ifndef TP2_APP_REGLAALWAYS_H
#define TP2_APP_REGLAALWAYS_H

#include "Regla.h"
#include <string>
#include <vector>
class ReglaAlways : public Regla{
 public:
  ReglaAlways(unsigned int src, unsigned int dst, unsigned int threshold,
        std::vector<std::string> words);
  virtual bool aplicar(Paquete &paquete) override;
};

#endif //TP2_APP_REGLAALWAYS_H
