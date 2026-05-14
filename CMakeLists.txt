cmake_minimum_required(VERSION 3.15)

project(SmartMemoryAllocator)

SET(CMAKE_C_STANDARD 17)

set(SOURCE_FILES main.c)

add_executable(SmartMemoryAllocator ${SOURCE_FILES})