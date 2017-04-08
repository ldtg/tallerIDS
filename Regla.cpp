//
// Created by tg on 07/04/17.
//

#include "Regla.h"
Regla::Regla(std::string regla) {
  std::vector<std::string> tokens;
  std::size_t pFin = regla.find(" ", 0);
  std::size_t pInicio = 0;
  while (pInicio != pFin + 1) {
    tokens.push_back(regla.substr(pInicio, pFin - pInicio));
    pInicio = pFin + 1;
    pFin = regla.find(" ", pInicio);
    if (pFin == std::string::npos) {
      pFin = regla.length() - 1; //Evita el ; final
    }
  }
  src = (unsigned int)std::stoi(tokens.at(0), nullptr, 16);
  dst = (unsigned int)std::stoi(tokens.at(1), nullptr, 16);
  threshold = (unsigned int)std::stoi(tokens.at(2), nullptr, 16);
  
}
