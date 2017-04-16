#include <iostream>
#include <string>
#include <vector>
#include "Ids.h"
int main(int argc, char *argv[]) {
  if (argc < 2)
    return 1;

  EnsambladorMonitor ensamblador;
  DetectorMonitor dtk(argv[1]);
  std::vector<Thread *> threads;
  std::vector<std::string> files;

  for (int i = 2; i < argc; i++) {
    std::string cString = argv[i];
    files.push_back(cString);
  }
  for (auto &&file : files) {
    threads.push_back(new Ids(file, ensamblador, dtk));
  }
  for (auto &&thread : threads) {
    thread->start();
  }
  for (auto &&thread : threads) {
    thread->join();
    delete thread;
  }

  return 0;
}
