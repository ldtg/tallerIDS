//
// Created by tg on 09/04/17.
//

#include "ReglaAlways.h"

bool ReglaAlways::aplicar(Paquete &paquete) {
   if(Regla::SDTAplica(paquete)){
     threshold--;
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
