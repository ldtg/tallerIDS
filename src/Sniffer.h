#ifndef TP2_APP_SNIFFER_H
#define TP2_APP_SNIFFER_H
#include <iostream>
#include <fstream>
#include <string>
#include "Paquete.h"

class Sniffer {
 private:
  std::ifstream file;
  bool eof;
 public:
  explicit Sniffer(std::string filePath);
  Paquete sniff();
  bool termino();
  ~Sniffer();
};

#endif //TP2_APP_SNIFFER_H
