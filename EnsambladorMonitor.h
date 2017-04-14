#ifndef TP2_APP_GESTORMONITOR_H
#define TP2_APP_GESTORMONITOR_H

#include <mutex>
#include "Ensamblador.h"
class EnsambladorMonitor {
 private:
  Ensamblador ensamblador;
  std::mutex mutex;
 public:
  explicit EnsambladorMonitor();
  Paquete agregar(const Paquete& paquete);
  EnsambladorMonitor(const EnsambladorMonitor &) = delete;
  EnsambladorMonitor &operator=(const EnsambladorMonitor &) = delete;
  ~EnsambladorMonitor();
};

#endif //TP2_APP_GESTORMONITOR_H
