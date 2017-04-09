#include <iostream>
#include <vector>
#include <algorithm>
#include "Paquete.h"
#include "Sniffer.h"
#include "Gestor.h"
#include "Ids.h"
#include "Detector.h"
#include "Regla.h"
int main() {
  GestorMonitor gestor;
  Ids ids("packets.cap", gestor);
  ids.run();/*
  int myints[]={10,20,30,40,50,60,70};
  std::vector<int> myvector;
  std::vector<int> otrovector;
  otrovector.resize(10);
  std::fill(otrovector.begin(),otrovector.end(),10);
  myvector.resize(10);   // allocate space for 7 elements

  std::copy_n ( otrovector.begin(), 7, myvector.begin() );

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';*/

  return 0;
}