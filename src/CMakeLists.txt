cmake_minimum_required(VERSION 3.25)

project(LoggerLib)

add_library(logger SHARED logger.cpp)

target_compile_features(logger PRIVATE cxx_std_17)

target_include_directories(logger PUBLIC ${CMAKE_SOURCE_DIR})