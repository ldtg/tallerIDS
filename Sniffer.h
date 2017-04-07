//
// Created by tg on 06/04/17.
//

#ifndef TP2_APP_SNIFFER_H
#define TP2_APP_SNIFFER_H
#include <iostream>
#include <fstream>
#include <string>
#include "Paquete.h"

class Sniffer {
 private:
  std::ifstream file;
  std::streampos begin, end, cur;
  std::streamoff size;
 public:
  Sniffer(std::string filePath);
  Paquete sniff(bool *eof);
  ~Sniffer();
};

#endif //TP2_APP_SNIFFER_H
