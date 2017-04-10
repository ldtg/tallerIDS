//
// Created by tg on 07/04/17.
//
#include <algorithm>

#include "Regla.h"
/*std::vector<std::string> Regla::llenarTokens(std::string regla) {
  std::vector<std::string> tokens;
  std::size_t pFin = regla.find(" ", 0);
  std::size_t pInicio = 0;
  while (pFin != regla.length() - 1) {
    tokens.push_back(regla.substr(pInicio, pFin - pInicio));
    pInicio = pFin + 1;
    pFin = regla.find(" ", pInicio);
    if (pFin == std::string::npos) {
      pFin = regla.length() - 1; //Evita el ; final
    }
  }
  return tokens;
}*/
bool Regla::srcAplica(unsigned int src) {
  if (this->src != 0) {
    return this->src == src;
  }
  return true;
}
bool Regla::dstAplica(unsigned int dst) {
  if (this->dst != 0) {
    return this->dst == dst;
  }
  return true;
}
bool Regla::SDTAplica(Paquete &paquete) {
  bool src, dst;
  src = srcAplica(paquete.getSrc());
  dst = dstAplica(paquete.getDst());
  return src&&dst&&threshold<=0;
}
/*Regla Regla::crearRegla(std::string sRegla) {
  unsigned int src,dst,threshold;
  std::string keyword;
  std::vector<std::string> words;
  std::vector<std::string> tokens = llenarTokens(sRegla);
  src = (unsigned int) std::stoi(tokens.at(0), nullptr, 16);
  dst = (unsigned int) std::stoi(tokens.at(1), nullptr, 16);
  threshold = (unsigned int) std::stoi(tokens.at(2), nullptr, 16);
  keyword = tokens.at(3);
  tokens.erase(tokens.begin(), tokens.begin() + 4);
  words.resize(tokens.size());
  words = std::move(tokens);

  if(keyword == "always")
    return  ReglaAlways(src,dst,threshold,words);
  if(keyword == "any")
    return  ReglaAny(src,dst,threshold,words);
  if(keyword == "all")
    return  ReglaAll(src,dst,threshold,words);
  return nullptr;
}*/
Regla::Regla(unsigned int src,
             unsigned int dst,
             unsigned int threshold,
             std::vector<std::string> words) : src(src), dst(dst), threshold
    (threshold), words(words){}



