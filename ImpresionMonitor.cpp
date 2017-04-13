//
// Created by tg on 11/04/17.
//

#include <iostream>
#include <string>
#include "ImpresionMonitor.h"
#include "Lock.h"
void ImpresionMonitor::imprimir(std::string mensaje) {
  Lock lock(mutex);
  std::cout << mensaje;
}
