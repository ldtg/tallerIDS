cmake_minimum_required(VERSION 3.7)
project(TP2_APP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -pedantic -Wall")
#set(SOURCE_FILES main.cpp Paquete.cpp Paquete.h Sniffer.cpp Sniffer.h Lock
#.cpp Lock.h PaquetesMonitor.cpp PaquetesMonitor.h PaqsCompletosMon.cpp
#PaqsCompletosMon.h Gestor.cpp Gestor.h Thread.cpp Thread.h Ids.cpp Ids.h Id
#.cpp Id.h Detector.cpp Detector.h Regla.cpp Regla.h GestorMonitor.cpp
#GestorMonitor.h)
set(SOURCE_FILES main.cpp Paquete.cpp Paquete.h Sniffer.cpp Sniffer.h Id.cpp Id.h)
add_executable(TP2_APP ${SOURCE_FILES})