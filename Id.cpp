#include "Id.h"
bool Id::operator==(const Id &p) const {
  return ((this->paqid == p.paqid) && (this->dst == p.dst)
      && (this->src == p.src));
}

bool Id::operator<(const Id &p) const {
  return (this->dst < p.dst) && (this->paqid < p.paqid) && (this->src < p
      .src);
}
Id::Id(unsigned int src, unsigned int dst, unsigned short id) : src(src), dst
    (dst), paqid(id) {}
unsigned int Id::getSrc() const {
  return this->src;
}
unsigned int Id::getDst() const {
  return this->dst;
}
unsigned short Id::getPaqId() const {
  return this->paqid;
}
Id::Id() {
  this->paqid = 0;
  this->dst = 0;
  this->src = 0;
}
