cmake_minimum_required(VERSION 3.25)

project(LoggerLib)

add_library(logger STATIC logger.cpp)

target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS logger
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)

install(FILES logger.h DESTINATION include)