#include "ReglaAlways.h"
#include <string>
#include <vector>
bool ReglaAlways::aplicar(const Paquete &paquete) {
  if (Regla::SDAplica(paquete)) {
    if (threshold > 1) {
      threshold--;
      return false;
    }
    return true;
  }
  return false;
}

ReglaAlways::ReglaAlways(unsigned int src,
                         unsigned int dst,
                         unsigned int threshold,
                         std::vector<std::string> words) : Regla(src,
                                                                 dst,
                                                                 threshold,
                                                                 words) {
}
