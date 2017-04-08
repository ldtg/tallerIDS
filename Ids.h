//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_IDS_H
#define TP2_APP_IDS_H

#include "Thread.h"
#include "Sniffer.h"
#include "GestorMonitor.h"
class Ids : public Thread{
 private:
  GestorMonitor& gestor;
  Sniffer sniffer;
  //Detector& detector;
 public:
  Ids(std::string archivo, GestorMonitor& gest);
  virtual void run();

};

#endif //TP2_APP_IDS_H
