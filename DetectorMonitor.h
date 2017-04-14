#ifndef TP2_APP_DETECTORMONITOR_H
#define TP2_APP_DETECTORMONITOR_H

#include "Detector.h"
class DetectorMonitor {
 private:
  Detector detector;
  std::mutex mutex;
 public:
  DetectorMonitor(std::string configFile, ImpresionMonitor &impresion);
  void aplicar(const Paquete &paquete);
};

#endif //TP2_APP_DETECTORMONITOR_H
