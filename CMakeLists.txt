cmake_minimum_required(VERSION 3.7)
project(TP2_APP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Paquete.cpp Paquete.h Sniffer.cpp Sniffer.h)
add_executable(TP2_APP ${SOURCE_FILES})