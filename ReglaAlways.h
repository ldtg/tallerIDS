#ifndef TP2_APP_REGLAALWAYS_H
#define TP2_APP_REGLAALWAYS_H

#include "Regla.h"
#include <string>
#include <vector>
class ReglaAlways : public Regla{
 public:
  ReglaAlways(unsigned int src, unsigned int dst, unsigned int threshold,
        std::vector<std::string> words);
  virtual bool aplicar(const Paquete &paquete) override;
  ~ReglaAlways();
};

#endif //TP2_APP_REGLAALWAYS_H
