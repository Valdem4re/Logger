#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <cstdarg>
#include <iostream>

class Logger {
    public:
    static void info(const char* format, ...);

    static void warning(const char* format, ...);

    static void error(const char* format, ...);

    static void debug(const char* format, ...);

    private:

    enum LogLevel {INFO, WARN, ERROR, DEBUG};

    static void setOutputColor(const LogLevel& lvl);
    static void resetOutputColor();
};

#endif // LOGGER_H