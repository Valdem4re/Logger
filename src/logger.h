#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <cstdarg>
#include <iostream>



class Logger {
    public:
    enum LogOutput {CONSOLE, FILE, STREAM}; 
    static void info(const char* format, ...);

    static void warning(const char* format, ...);

    static void error(const char* format, ...);

    static void debug(const char* format, ...);

    static void setLoggingOutput(std::ostream& output);

    private:

    enum LogLevel {INFO, WARN, ERROR, DEBUG};

    static void setOutputColor(const LogLevel& lvl);
    static void resetOutputColor();

    static std::ostream* log_output_stream_;


};

#endif // LOGGER_H