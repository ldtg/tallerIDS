#ifndef TP2_APP_DETECTORMONITOR_H
#define TP2_APP_DETECTORMONITOR_H

#include <mutex>
#include <string>
#include "Detector.h"
class DetectorMonitor {
 private:
  Detector detector;
  std::mutex mutex;
 public:
  explicit DetectorMonitor(std::string configFile);
  void aplicar(const Paquete &paquete);
  ~DetectorMonitor();
  DetectorMonitor(const DetectorMonitor &) = delete;
  DetectorMonitor &operator=(const DetectorMonitor &) = delete;
};

#endif //TP2_APP_DETECTORMONITOR_H
