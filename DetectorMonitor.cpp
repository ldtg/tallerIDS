#include "DetectorMonitor.h"
#include "Lock.h"
DetectorMonitor::DetectorMonitor(std::string configFile,
                                 ImpresionMonitor &impresion) : detector
                                                                    (configFile,
                                                                     impresion) {
}
void DetectorMonitor::aplicar(const Paquete &paquete) {
  Lock(this->mutex);
  this->detector.aplicar(paquete);
}
