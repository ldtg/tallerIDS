//
// Created by tg on 09/04/17.
//

#ifndef TP2_APP_REGLAALL_H
#define TP2_APP_REGLAALL_H

#include "Regla.h"
#include <string>
#include <vector>
class ReglaAll : public Regla {
 public:
  ReglaAll(unsigned int src, unsigned int dst, unsigned int threshold,
           std::vector<std::string> words);
  virtual bool aplicar(const Paquete &paquete) override;
};

#endif //TP2_APP_REGLAALL_H
