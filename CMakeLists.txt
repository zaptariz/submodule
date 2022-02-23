cmake_minimum_required(VERSION 3.10)

project(BeldexMQ)

add_subdirectory(src)
add_subdirectory(external)

add_executable(beldexMQ src/bmq_connection.cpp)
target_include_directories(beldexMQ 
    PUBLIC 
        external/cppzmq
        external/bmq
)