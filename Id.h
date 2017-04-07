//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_ID_H
#define TP2_APP_ID_H

#include "Paquete.h"
class Id {
 private:
  unsigned int src;
  unsigned int dst;
  unsigned short id;
 public:
  Id(Paquete paq);
  bool operator ==(const Id &p) const;
  bool operator <(const Id &p) const;

};

#endif //TP2_APP_ID_H
