cmake_minimum_required(VERSION 3.27)
project(WineClassifier)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)