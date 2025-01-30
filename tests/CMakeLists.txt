cmake_minimum_required(VERSION 3.0)

project(LoggerTests)

add_executable(logger_test logger_test.cpp)

target_link_libraries(logger_test PRIVATE logger)

target_include_directories(logger_test PRIVATE ../src)
