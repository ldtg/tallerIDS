#ifndef TP2_APP_REGLA_H
#define TP2_APP_REGLA_H
#include <string>
#include <vector>
#include "Paquete.h"

class Regla {
 protected:
  unsigned int src;
  unsigned int dst;
  unsigned int threshold;
  std::vector<std::string> words;
  bool dstAplica(unsigned int src);
  bool srcAplica(unsigned int src);
  bool SDAplica(const Paquete &paquete);
  Regla(unsigned int src, unsigned int dst, unsigned int threshold,
        std::vector<std::string> words);
 public:
  virtual bool aplicar(const Paquete &paquete) = 0;
  virtual ~Regla();
};

#endif //TP2_APP_REGLA_H
