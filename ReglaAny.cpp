//
// Created by tg on 09/04/17.
//

#include "ReglaAny.h"

bool ReglaAny::aplicar(Paquete &paquete) {
  std::string auxWord;
  std::vector<std::string>::iterator it;
  if(!Regla::SDTAplica(paquete))
    return false;

  for (it = words.begin(); it != words.end(); it++) {
    for (auto &&byte : paquete.getData()) {
      if (byte != 0) {
        auxWord.push_back(byte);
        if(auxWord.find(*it, 0) != auxWord.length()){
          threshold--;
          return true;
        }
      } else {
        auxWord.erase();
      }

    }
  }
  return false;
}
ReglaAny::ReglaAny(unsigned int src,
                   unsigned int dst,
                   unsigned int threshold,
                   std::vector<std::string> words) : Regla(src,
                                                           dst,
                                                           threshold,
                                                           words) {

}

