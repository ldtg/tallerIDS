//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_PAQSCOMPLETOSMON_H
#define TP2_APP_PAQSCOMPLETOSMON_H
#include <map>
#include <mutex>
#include <stack>
#include "Paquete.h"
class PaqsCompletosMon {
 private:
  std::stack<Paquete> paquetesCompletos;
  std::mutex mutexStack;
 public:
  PaqsCompletosMon();
  void push(Paquete &paquete);
  Paquete popSiNoVacio(bool *vacio);
};

#endif //TP2_APP_PAQSCOMPLETOSMON_H
