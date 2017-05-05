#include "Logger.h"
#include <string>
#include <iostream>
using namespace std;

const std::string LOG = "LOG";
const std::string SPACE = " ";

bool Logger::loggerOn = false;

void Logger::log(std::string message, std::string level) {
    if (loggerOn) {
        cout << LOG << SPACE << level << SPACE << message << endl;
    }
    return;
}

bool Logger::log(std::string message, std::string level, std::string logFilePath) {
    return false;
}
