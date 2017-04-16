#include "DetectorMonitor.h"
#include "Lock.h"
#include <string>
DetectorMonitor::DetectorMonitor(std::string configFile)
    : detector(configFile) {
}

void DetectorMonitor::aplicar(const Paquete &paquete) {
  Lock(this->mutex);
  this->detector.aplicar(paquete);
}

DetectorMonitor::~DetectorMonitor() {}
