cmake_minimum_required(VERSION 3.7)
project(TP2_APP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -pedantic -Wall")
set(SOURCE_FILES main.cpp Paquete.cpp Paquete.h Sniffer.cpp Sniffer.h Lock.cpp Lock.h Ensamblador.cpp Ensamblador.h Thread.cpp Thread.h Ids.cpp Ids.h IdPaquete.cpp IdPaquete.h Detector.cpp Detector.h Regla.cpp Regla.h EnsambladorMonitor.cpp EnsambladorMonitor.h ReglaAll.cpp ReglaAll.h ReglaAny.cpp ReglaAny.h ReglaAlways.cpp ReglaAlways.h DetectorMonitor.cpp DetectorMonitor.h)
add_executable(TP2_APP ${SOURCE_FILES})