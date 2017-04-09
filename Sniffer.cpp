//
// Created by tg on 06/04/17.
//

#include "Sniffer.h"
Sniffer::Sniffer(std::string filePath) : file(filePath, std::ios::binary),
                                         eof(false) {}
Sniffer::~Sniffer() {
  if (file.is_open())
    file.close();
}
Paquete Sniffer::sniff() {
  std::vector<char> header;
  Paquete nullpkg;
  if (!this->termino()) {
    //file.read(header, HEADER_SIZE);
    header.resize(HEADER_SIZE);
    file.read(&header[0], HEADER_SIZE);
    if (file.eof()) {
      this->eof = true;
      return nullpkg;
    }

    Paquete paquete(header);
    int dataL = paquete.getLongitudDatos();
    std::vector<char> data(dataL);
    file.read(&data[0], dataL);
    paquete.setData(data, dataL);
    if (file.eof()) {
      this->eof = true;
    }
    return paquete;
  }
  this->eof = true;
  return nullpkg;
}
bool Sniffer::termino() {
  return !file.is_open() || file.eof();
}
