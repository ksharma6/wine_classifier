cmake_minimum_required(VERSION 3.13)
project(WineClassifier)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ../bin/)
add_executable(${PROJECT_NAME} main.cpp)
#target_link_directories(WineClassifier PRIVATE ${CMAKE_SOURCE_DIR}/src/SomeLib/cpp/build/)
#target_link_libraries(WineClassifier mearlymath)


