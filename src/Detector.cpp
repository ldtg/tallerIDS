#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Detector.h"
#include "ReglaAlways.h"
#include "ReglaAny.h"
#include "ReglaAll.h"
Detector::Detector(std::string configFile) {
  std::ifstream inFile(configFile);
  std::string keyword;
  std::vector<std::string> words;
  while (!inFile.eof()) {
    std::vector<std::string> tokens = llenarTokens(&inFile);
    if (tokens.size() > 3) {
      unsigned int src = (unsigned int) std::stoi(tokens.at(0), nullptr, 16);
      unsigned int dst = (unsigned int) std::stoi(tokens.at(1), nullptr, 16);
      unsigned int threshold = (unsigned int) std::stoi(tokens.at(2),
                                                        nullptr, 16);
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
  }
  inFile.close();
}

void Detector::aplicar(const Paquete &paquete) {
  std::vector<Regla *>::iterator it;
  if (!fueProcesado(paquete)) {
    for (it = reglas.begin(); it != reglas.end(); it++) {
      if ((*it)->aplicar(paquete))
        imprimirAlerta(std::distance(reglas.begin(), it), paquete);
    }
    paquetesProcesados.push_back(paquete);
  }
}

Detector::~Detector() {
  for (auto &&regla : reglas) {
    delete (regla);
  }
}

std::vector<std::string> Detector::llenarTokens(std::ifstream *inFile) {
  std::string token;
  std::vector<std::string> tokens;
  while (*inFile >> token && token != ";") {
    tokens.push_back(token);
  }
  return tokens;
}

void Detector::imprimirAlerta(long pos, const Paquete &paquete) {
  std::cout << std::hex;
  std::cout << "Rule " << pos << ": ";
  std::cout << "ALERT! " << paquete.getSrc() << " -> " << paquete.getDst()
            << ":";
  for (auto &&byte : paquete.getData()) {
    std::cout << " ";
    std::cout << (int) byte;
  }
  std::cout << std::endl;
}

bool Detector::fueProcesado(const Paquete &paquete) {
  return std::find(paquetesProcesados.begin(), paquetesProcesados.end(),
                   paquete) != paquetesProcesados.end();
}
