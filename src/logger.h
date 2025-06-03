#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <cstdarg>
#include <iostream>

class Logger {
    public:
    enum LogOutput {CONSOLE, FILE, STREAM}; 

    template<class... Args>
    static void info(const char* format, Args... args);

    template<class... Args>
    static void warning(const char* format, Args... args);

    template<class... Args>
    static void error(const char* format, Args... args);

    template<class... Args>
    static void debug(const char* format, Args... args);

    static void setLoggingOutput(std::ostream& output);

    private:

    enum LogType {LOG_INFO, LOG_WARN, LOG_ERROR, LOG_DEBUG};

    static void setOutputColor(const LogType& type);
    static void resetOutputColor();
    static void usePrefix(const LogType& type);

    template<class... Args>
    static void printLog(const LogType type, const char* format, Args... args);

    static std::ostream* log_output_stream_;


};

#endif // LOGGER_H