//
// Created by tg on 07/04/17.
//

#include "Thread.h"
void Thread::start() {
  thread = std::thread(&Thread::run, this);
}
void Thread::join() {
    thread.join();
}