//
// Created by tg on 07/04/17.
//

#include "Lock.h"
Lock::Lock(std::mutex &m) : m(m) {
  m.lock();
}
Lock::~Lock() {
  m.unlock();
}
