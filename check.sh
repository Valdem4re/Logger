#!/bin/bash

SRC_DIR="src"
TESTS_DIR="tests"
BUILD_DIR="build"
TEST_EXEC="logger_test"

if [ ! -f "$BUILD_DIR/liblogger.so" ]; then
    echo "[Tests] Build directory does not contain the compiled library."
    echo "[Tests] Please compile the library first."
    exit 1
fi


echo "[Tests] Compiling tests..."

cd "$TESTS_DIR" || exit 1

g++ -std=c++17 -o "$TEST_EXEC" logger_test.cpp -I"../$SRC_DIR" -L"../$BUILD_DIR" -llogger -Wl,-rpath,"../$BUILD_DIR"

if [ $? -ne 0 ]; then
    echo "[Tests] Compilation failed!"
    rm -rf logger_test log.txt
    exit 1
fi

echo "[Tests] Running tests..."
./logger_test

if [ $? -eq 0 ]; then
    echo "[Tests] Tests passed successfully!"
else
    echo "[Tests] Tests failed!"
    rm -rf logger_test log.txt
    exit 1
fi

rm -rf logger_test log.txt
