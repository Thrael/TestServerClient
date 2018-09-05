#include <cstring>
#include "Logger.h"

Logger::Logger(loglevel level, std::unique_ptr<std::ostream> os) {
    {
        if(os) {
            resource = std::move(os);
            outputStream = os.get();
        }else{
            outputStream = &std::cout;
        }

        setFormat("%H:%M:%S");
        setLogLevel(level);

    }
}

void Logger::setLogLevel(const loglevel &level){
    std::lock_guard<std::mutex> lockGuard(this->lock);
    for (auto& f : loggers) {
            f = [](const char*) {};
        }

    switch (level) {
            case DEBUG:
                loggers[DEBUG] =
                        [this](const char* str) {
                            std::lock_guard<std::mutex> lockGuard(this->lock);
                            *outputStream << "[" << std::put_time(get_cur_time(), format) << "]" << "[DEBUG]" << str << std::endl;};
            case INFO:
                loggers[INFO] =
                        [this](const char* str) {
                            std::lock_guard<std::mutex> lockGuard(this->lock);
                            *outputStream << "[" << std::put_time(get_cur_time(), format) << "]" << "[INFO]" << str << std::endl;};
            case ERROR:
                loggers[ERROR] =
                        [this](const char* str) {
                            std::lock_guard<std::mutex> lockGuard(this->lock);
                            *outputStream << "[" << std::put_time(get_cur_time(), format) << "]" << "[ERROR]" << str << std::endl;};
            default:
                break;
        }
}

void Logger::setFormat(const char *format) {
    std::lock_guard<std::mutex> lockGuard(this->lock);
    std::strcpy(this->format,format);
}

void Logger::logDebug(const char *message) {
    loggers[loglevel::DEBUG](message);
}

void Logger::logInfo(const char *message) {
    loggers[loglevel::INFO](message);
}

void Logger::logError(const char *message) {
    loggers[loglevel::ERROR](message);
}

std::tm* Logger::get_cur_time() {
    std::time_t t = std::time(nullptr);
    //TODO: change with thread-safe  localtime_r(); (time.h)
    return std::localtime(&t);
}
