cmake_minimum_required(VERSION 3.21.3)
project(WineClassifier)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ../bin/)

add_subdirectory(src/etl)
add_subdirectory(src/lib/eigen)

include_directories(${PROJECT_SOURCE_DIR}/src) #Add the given directories to those the compiler uses to search for include files.

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/etl/etl.cpp)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE etl
    PRIVATE eigen  
    )