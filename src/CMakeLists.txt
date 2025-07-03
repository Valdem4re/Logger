cmake_minimum_required(VERSION 3.25)

project(LoggerLib)

include(FetchContent)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.2.1
)

FetchContent_MakeAvailable(fmt)

add_library(logger STATIC logger.cpp)

target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(logger PUBLIC fmt::fmt)

install(TARGETS logger
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)

install(FILES logger.h DESTINATION include)
