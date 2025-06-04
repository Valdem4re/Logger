#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <cstdarg>
#include <iostream>

#define LOG_MSG_BUF_SIZE 1024

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


template<class... Args>
void Logger::info(const char* format, Args... args) {
    printLog(LOG_INFO, format, args...);
};

template<class... Args>
void Logger::warning(const char* format, Args... args) {
    printLog(LOG_WARN, format, args...);
};

template<class... Args>
void Logger::error(const char* format, Args... args) {
    printLog(LOG_ERROR, format, args...);
};

template<class... Args>
void Logger::debug(const char* format, Args... args) {
    printLog(LOG_DEBUG, format, args...);
};

template<class... Args>
void Logger::printLog(const LogType type, const char* format, Args... args) {
    usePrefix(type);

    char buf[LOG_MSG_BUF_SIZE];
    std::snprintf(buf, LOG_MSG_BUF_SIZE, format, args...);

    *log_output_stream_ << buf << std::endl;
    log_output_stream_->flush();
}

#endif // LOGGER_H