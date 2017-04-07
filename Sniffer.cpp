//
// Created by tg on 06/04/17.
//

#include "Sniffer.h"
Sniffer::Sniffer(std::string filePath) : file(filePath, std::ios::binary) {
}
Paquete Sniffer::sniff(bool *eof) {
  *eof = false;
  char header[HEADER_SIZE] = "";
  Paquete nullpkg;
  if (file.is_open() && !file.eof()) {
    file.read(header, HEADER_SIZE);
    if (file.eof()) {
      *eof = true;
      return nullpkg;
    }

    Paquete paquete(header);
    int dataL = paquete.getLongitudDatos();
    char data[MAX_LEN_DATA];
    file.read(data, dataL);
    paquete.setData(data, dataL);
    if (file.eof()) {
      *eof = true;
    }
    return paquete;
  }
  *eof = true;
  return nullpkg;
}
Sniffer::~Sniffer() {
  if (file.is_open())
    file.close();
}
