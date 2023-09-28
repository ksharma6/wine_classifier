cmake_minimum_required(VERSION 3.13)
project(WineClassifier)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ../bin/)
add_executable(${PROJECT_NAME} src/main.cpp
                etl/etl.h)

add_subdirectory(etl)
target_link_libraries(${PROJECT_NAME} etl)
#target_link_directories(WineClassifier PRIVATE ${CMAKE_SOURCE_DIR}/src/SomeLib/cpp/build/)
#target_link_libraries(WineClassifier mearlymath)


