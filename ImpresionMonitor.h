//
// Created by tg on 11/04/17.
//

#ifndef TP2_APP_IMPRESIONMONITOR_H
#define TP2_APP_IMPRESIONMONITOR_H

#include <mutex>
#include <sstream>
#include <string>
class ImpresionMonitor {
 private:
  std::mutex mutex;
 public:
  void imprimir(std::string mensaje);
};

#endif //TP2_APP_IMPRESIONMONITOR_H
