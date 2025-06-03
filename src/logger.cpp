#include "logger.h"

#ifdef _WIN32
#include <windows.h>
#endif


#define LOGGER_INFO_PREFIX     "\n[INFO lol] "
#define LOGGER_WARN_PREFIX     "\n[WARN] "
#define LOGGER_ERROR_PREFIX    "\n[ERROR] "
#define LOGGER_FATAL_PREFIX    "\n[FATAL] "
#define LOGGER_DEBUG_PREFIX    "\n[DEBUG] "

#define LOG_MSG_BUF_SIZE 1024

std::ostream* Logger::log_output_stream_ = &std::cout; // default

void Logger::setLoggingOutput(std::ostream& output) {
    log_output_stream_ = &output;
}

void Logger::usePrefix(const LogType& type) {
    setOutputColor(type);
    switch (type) {
        case LOG_INFO:  *log_output_stream_ << LOGGER_INFO_PREFIX;  break;
        case LOG_WARN:  *log_output_stream_ << LOGGER_WARN_PREFIX;  break;
        case LOG_ERROR: *log_output_stream_ << LOGGER_ERROR_PREFIX; break;
        case LOG_DEBUG: *log_output_stream_ << LOGGER_DEBUG_PREFIX; break;
        default: break;
    }
    resetOutputColor();
}

template<class... Args>
void Logger::printLog(const LogType type, const char* format, Args... args) {
    usePrefix(type);

    char buf[LOG_MSG_BUF_SIZE];
    std::snprintf(buf, LOG_MSG_BUF_SIZE, format, args...);

    *log_output_stream_ << buf << std::endl;
    log_output_stream_->flush();
}

template<class... Args>
void Logger::info(const char* format, Args... args) {
    printLog(LOG_INFO, format, args);
};

template<class... Args>
void Logger::warning(const char* format, Args...) {
    use_prefix(LOG_WARN);
    va_list args;
    va_start(args, format);
    std::vprintf(format, args);
    va_end(args);
    *log_output_stream_  << std::endl;
    log_output_stream_->flush();
};

template<class... Args>
void Logger::error(const char* format, Args...) {
    use_prefix(LOG_ERROR);
    va_list args;
    va_start(args, format);
    std::vprintf(format, args);
    va_end(args);
    *log_output_stream_  << std::endl;
    log_output_stream_->flush();
};

template<class... Args>
void Logger::debug(const char* format, Args...) {
    use_prefix(LOG_DEBUG);
    va_list args;
    va_start(args, format);
    std::vprintf(format, args);
    va_end(args);
    *log_output_stream_  << std::endl;
    log_output_stream_->flush();
};

void Logger::setOutputColor(const LogType& type) {
    #ifndef _WIN32 
    // Linux console color settigs
    switch (lvl)
    {
        case LogType::INFO:    std::cout << "\033[1;32m"; // Green
            break;
        case LogType::WARN:    std::cout << "\033[1;33m"; // Yellow
            break;
        case LogType::ERROR:   std::cerr << "\033[1;31m"; // Red
            break;
        case LogType::DEBUG:   std::cout << "\033[1;36m"; // Cyan
            break;

        default:
            break;
    }
    #else
    // Windows console color settings
    switch (type)
    {
        case LogType::LOG_INFO:    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case LogType::LOG_WARN:    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case LogType::LOG_ERROR:   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
            break;
        case LogType::LOG_DEBUG:   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
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