//
// Created by tg on 07/04/17.
//
#include <algorithm>

#include "Regla.h"
#include <string>
#include <vector>
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
bool Regla::SDAplica(Paquete &paquete) {
  bool src, dst;
  src = srcAplica(paquete.getSrc());
  dst = dstAplica(paquete.getDst());
  return src && dst;
}

Regla::Regla(unsigned int src,
             unsigned int dst,
             unsigned int threshold,
             std::vector<std::string> words) : src(src), dst(dst), threshold
    (threshold), words(words) {}
Regla::~Regla() {}



