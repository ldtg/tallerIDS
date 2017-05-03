#include "IdPaquete.h"
IdPaquete::IdPaquete() : id(0), dst(0), src(0){}

IdPaquete::IdPaquete(unsigned int src, unsigned int dst, unsigned short id)
    : src(src), dst(dst), id(id) {}

bool IdPaquete::operator==(const IdPaquete &p) const {
  return ((this->id == p.id) && (this->dst == p.dst)
      && (this->src == p.src));
}

IdPaquete::~IdPaquete() {}
