//
// Created by tg on 09/04/17.
//

#ifndef TP2_APP_REGLAANY_H
#define TP2_APP_REGLAANY_H

#include "Regla.h"
class ReglaAny : public Regla{
 public:
  ReglaAny(unsigned int src, unsigned int dst, unsigned int threshold,
              std::vector<std::string> words);
  virtual bool aplicar(Paquete &paquete) override;
};

#endif //TP2_APP_REGLAANY_H
