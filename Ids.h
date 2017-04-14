#ifndef TP2_APP_IDS_H
#define TP2_APP_IDS_H

#include "Thread.h"
#include "Sniffer.h"
#include "EnsambladorMonitor.h"
#include "Detector.h"
#include "DetectorMonitor.h"
#include <string>
class Ids : public Thread {
 private:
  EnsambladorMonitor &ensambladorMonitor;
  Sniffer sniffer;
  DetectorMonitor &detector;
 public:
  Ids(std::string archivo, EnsambladorMonitor &ensambladorMonitor,
      DetectorMonitor &dtk);
  virtual void run();
};

#endif //TP2_APP_IDS_H
