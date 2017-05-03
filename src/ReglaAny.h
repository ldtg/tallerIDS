#ifndef TP2_APP_REGLAANY_H
#define TP2_APP_REGLAANY_H

#include "Regla.h"
#include <string>
#include <vector>
class ReglaAny : public Regla {
 public:
  ReglaAny(unsigned int src, unsigned int dst, unsigned int threshold,
           std::vector<std::string> words);
  virtual bool aplicar(const Paquete &paquete) override;
  ~ReglaAny();
};

#endif //TP2_APP_REGLAANY_H
