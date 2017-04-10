//
// Created by tg on 07/04/17.
//

#include <fstream>
#include "Detector.h"
#include "ReglaAlways.h"
#include "ReglaAny.h"
#include "ReglaAll.h"
Detector::Detector(std::string configFile) {
  std::ifstream inFile(configFile);
  std::string sRegla;
  unsigned int src, dst, threshold;
  std::string keyword;
  while (inFile >> sRegla) {
    std::vector<std::string> words;
    std::vector<std::string> tokens = llenarTokens(sRegla);
    src = (unsigned int) std::stoi(tokens.at(0), nullptr, 16);
    dst = (unsigned int) std::stoi(tokens.at(1), nullptr, 16);
    threshold = (unsigned int) std::stoi(tokens.at(2), nullptr, 16);
    keyword = tokens.at(3);
    tokens.erase(tokens.begin(), tokens.begin() + 4);
    words.resize(tokens.size());
    words = std::move(tokens);

    if (keyword == "always")
      this->reglas.push_back(new ReglaAlways(src, dst, threshold, words));
    if (keyword == "any")
      this->reglas.push_back(new ReglaAny(src, dst, threshold, words));
    if (keyword == "all")
      this->reglas.push_back(new ReglaAll(src, dst, threshold, words));
  }
  inFile.close();
}

std::vector<std::string> Detector::llenarTokens(std::string regla) {
  std::vector<std::string> tokens;
  std::size_t pFin = regla.find(" ", 0);
  std::size_t pInicio = 0;
  while (pFin != regla.length() - 1) {
    tokens.push_back(regla.substr(pInicio, pFin - pInicio));
    pInicio = pFin + 1;
    pFin = regla.find(" ", pInicio);
    if (pFin == std::string::npos) {
      pFin = regla.length() - 1; //Evita el ; final
    }
  }
  return tokens;
}
Detector::~Detector() {
  for (auto &&regla : reglas) {
    delete (regla);
  }
}
void Detector::aplicar(Paquete &paquete) {
  std::vector<Regla *>::iterator it;
  for (it = reglas.begin(); it != reglas.end(); it++) {
    if ((*it)->aplicar(paquete))
      std::cout << "Regla :" << std::distance(reglas.begin(), it);
  }
}
