#include "ReglaAll.h"
#include <algorithm>
#include <string>
#include <vector>
ReglaAll::ReglaAll(unsigned int src,
                   unsigned int dst,
                   unsigned int threshold,
                   std::vector<std::string> words) : Regla(src,
                                                           dst,
                                                           threshold,
                                                           words) {}

bool ReglaAll::aplicar(const Paquete &paquete) {
  std::vector<bool> boolWords(words.size());
  std::string auxWord;
  std::vector<std::string>::iterator it;
  if (!Regla::SDAplica(paquete))
    return false;

  for (it = words.begin(); it != words.end(); it++) {
    for (auto &&byte : paquete.getData()) {
      if (byte != 0) {
        auxWord.push_back(byte);
        boolWords[std::distance(words.begin(), it)] =
            auxWord.find(*it, 0) != std::string::npos;
      } else {
        auxWord.erase();
      }
    }
  }
  if (std::find(boolWords.begin(), boolWords.end(), false) == boolWords.end()) {
    if (threshold > 1) {
      threshold--;
      return false;
    }
    return true;
  }
  return false;
}
ReglaAll::~ReglaAll() {}
