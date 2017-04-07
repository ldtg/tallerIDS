cmake_minimum_required(VERSION 3.7)
project(TP2_APP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -pedantic")
set(SOURCE_FILES main.cpp Paquete.cpp Paquete.h Sniffer.cpp Sniffer.h Lock.cpp Lock.h PaquetesMonitor.cpp PaquetesMonitor.h PaqsCompletosMon.cpp PaqsCompletosMon.h Ensamblador.cpp Ensamblador.h Thread.cpp Thread.h Ids.cpp Ids.h Id.cpp Id.h)
add_executable(TP2_APP ${SOURCE_FILES})