cmake_minimum_required(VERSION 3.23)
project(Knight_Proj)

set(CMAKE_CXX_STANDARD 23)

add_executable(Knight_Proj main.cpp ChessB.h ChessB.cpp Node.h Node.cpp Constant.cpp)
