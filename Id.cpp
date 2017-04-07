//
// Created by tg on 07/04/17.
//

#include "Id.h"
bool Id::operator==(const Id &p) const {
  return ((this->id == p.id) && (this->dst == p.dst) && (this->src == p.src));
}
Id::Id(Paquete paq) : id(paq.getId()), src(paq.getSrc()), dst(paq.getDst()){

}
bool Id::operator<(const Id &p) const {
  return (this->dst < p.dst) || (this->id< p.id) || (this->src < p.src);
}
