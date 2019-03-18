cmake_minimum_required(VERSION 3.13)
project(Pr1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pr3 src/main3.cpp include/Number.h include/Number_bin.h src/NumberException.cpp include/NumberException.h src/main3.cpp src/NumberBase.cpp include/NumberBase.h src/BinaryNumber.cpp include/BinaryNumber.h src/OctalNumber.cpp include/OctalNumber.h src/HexadecimalNumber.cpp include/HexadecimalNumber.h src/DecimalNumber.cpp include/DecimalNumber.h)