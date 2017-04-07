//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_THREAD_H
#define TP2_APP_THREAD_H

#include <thread>
class Thread {
 private:
  std::thread thread;

 public:
  Thread () {}

  void start();

  void join();

  virtual void run() = 0;
  virtual ~Thread() {}

  Thread(const Thread&) = delete;
  Thread& operator=(const Thread&) = delete;

  Thread(Thread&& other) {
    this->thread = std::move(other.thread);
  }

  Thread& operator=(Thread&& other) {
    this->thread = std::move(other.thread);
    return *this;
  }
};

#endif //TP2_APP_THREAD_H
