cmake_minimum_required(VERSION 3.0)

project(LoggerLib)

add_library(logger SHARED logger.cpp)

target_compile_features(logger PRIVATE cxx_std_17)