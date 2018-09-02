#ifndef TESTSERVER_LOGGER_H
#define TESTSERVER_LOGGER_H


#include <iosfwd>
#include <ostream>
#include <iostream>
#include <memory>
#include <functional>
#include <iomanip>
#include <chrono>
#include <mutex>

enum loglevel {INFO,DEBUG,ERROR};
#define LOGLEVELS_NUM 3

class Logger {
private:
    std::ostream* outputStream;
    std::unique_ptr<std::ostream> resource;
    char format[100];
    std::function<void(const char*)> loggers[LOGLEVELS_NUM];

public:
    Logger():Logger(loglevel::ERROR, nullptr){}
    explicit Logger(loglevel level, std::unique_ptr<std::ostream> os = nullptr);
    std::tm* get_cur_time();
    void setFormat(const char* format);
    void setLogLevel(const loglevel &level);
    void logDebug(const char* message);
    void logInfo(const char* message);
    void logError(const char* message);
};


#endif //TESTSERVER_LOGGER_H
