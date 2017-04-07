//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_IDS_H
#define TP2_APP_IDS_H

#include "Thread.h"
#include "Ensamblador.h"
#include "Sniffer.h"
class Ids : public Thread{
 private:
  Ensamblador& ensamblador;
  Sniffer sniffer;
  //Detector& detector;
 public:
  Ids(std::string archivo, Ensamblador& ens);
  virtual void run();

};

#endif //TP2_APP_IDS_H
