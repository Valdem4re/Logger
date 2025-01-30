#include "logger.h"

#ifdef _WIN32
#include <windows.h>
#endif

void Logger::info(const char* format, ...) {
    setOutputColor(LogLevel::INFO);
    std::cout << "INFO: ";
    resetOutputColor();

    va_list args;
    va_start(args, format);
    std::vprintf(format, args);
    va_end(args);
    std::cout << std::endl;
    std::cout.flush();
};

void Logger::warning(const char* format, ...) {
    setOutputColor(LogLevel::WARN);
    std::cout << "WARNING: ";
    resetOutputColor();

    va_list args;
    va_start(args, format);
    std::vprintf(format, args);
    va_end(args);
    std::cout << std::endl;
    std::cout.flush();
};

void Logger::error(const char* format,...) {
    setOutputColor(LogLevel::ERROR);
    std::cerr << "ERROR: ";
    resetOutputColor();

    va_list args;
    va_start(args, format);
    std::vprintf(format, args);
    va_end(args);
    std::cerr << std::endl;
    std::cerr.flush();
};

void Logger::debug(const char* format,...) {
    setOutputColor(LogLevel::DEBUG);
    std::cout << "DEBUG: ";
    resetOutputColor();

    va_list args;
    va_start(args, format);
    std::vprintf(format, args);
    va_end(args);
    std::cout << std::endl;
    std::cout.flush();
};

void Logger::setOutputColor(const LogLevel& lvl) {
    #ifndef _WIN32 
    // Linux console color settigs
    switch (lvl)
    {
        case LogLevel::INFO:    std::cout << "\033[1;32m"; // Green
            break;
        case LogLevel::WARN:    std::cout << "\033[1;33m"; // Yellow
            break;
        case LogLevel::ERROR:   std::cerr << "\033[1;31m"; // Red
            break;
        case LogLevel::DEBUG:   std::cout << "\033[1;36m"; // Cyan
            break;

        default:
            break;
    }
    #else
    // Windows console color settings
    switch (lvl)
    {
        case LogLevel::INFO:    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
            break;
        case LogLevel::WARN:    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_YELLOW);
            break;
        case LogLevel::ERROR:   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            break;
        case LogLevel::DEBUG:   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;

        default:
            break;
    }
    #endif
}

void Logger::resetOutputColor() { 
    #ifndef _WIN32
    std::cout << "\033[0m";
    #else
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
         FOREGROUND_RED   |
         FOREGROUND_GREEN |
         FOREGROUND_BLUE);
    #endif
}