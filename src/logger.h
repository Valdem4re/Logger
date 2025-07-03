#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <cstdarg>
#include <iostream>
#include <fmt/core.h>

#define LOG_MSG_BUF_SIZE 1024

class Logger {
    public:
    enum LogOutput {CONSOLE, FILE, STREAM}; 

    template<class... Args>
    static void info(fmt::format_string<Args...> fmt, Args&&... args);

    template<class... Args>
    static void warning(fmt::format_string<Args...> fmt, Args&&... args);

    template<class... Args>
    static void error(fmt::format_string<Args...> fmt, Args&&... args);

    template<class... Args>
    static void debug(fmt::format_string<Args...> fmt, Args&&... args);

    static void setLoggingOutput(std::ostream& output);

    private:

    enum LogType {LOG_INFO, LOG_WARN, LOG_ERROR, LOG_DEBUG};

    static void setOutputColor(const LogType& type);
    static void resetOutputColor();
    static void usePrefix(const LogType& type);

    template<class... Args>
    static void printLog(const LogType type, fmt::format_string<Args...> fmt, Args&&... args);

    static std::ostream* log_output_stream_;


};


template<class... Args>
void Logger::info(fmt::format_string<Args...> fmt_str, Args&&... args) {
    printLog(LOG_INFO, fmt_str, args...);
};

template<class... Args>
void Logger::warning(fmt::format_string<Args...> fmt_str, Args&&... args) {
    printLog(LOG_WARN, fmt_str, args...);
};

template<class... Args>
void Logger::error(fmt::format_string<Args...> fmt_str, Args&&... args) {
    printLog(LOG_ERROR, fmt_str, args...);
};

template<class... Args>
void Logger::debug(fmt::format_string<Args...> fmt_str, Args&&... args) {
    printLog(LOG_DEBUG, fmt_str, args...);
};

template<class... Args>
void Logger::printLog(const LogType type, fmt::format_string<Args...> fmt_str, Args&&... args) {
    usePrefix(type);
    *log_output_stream_ << fmt::format(fmt_str, std::forward<Args>(args)...) << std::endl;
}

#endif // LOGGER_H