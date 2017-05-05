#ifndef LOGGER_H
#define LOGGER_H
#include <string>

class Logger {
    public:
        static bool loggerOn;
        static void log(std::string message, std::string level);
        static bool log(std::string message, std::string level, std::string logFilePath);
};

#endif // LOGGER_H
