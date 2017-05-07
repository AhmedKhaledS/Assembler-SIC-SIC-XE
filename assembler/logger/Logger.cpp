#include "Logger.h"
#include <string>
#include <iostream>
#include "LoggerConstants.h"

using namespace std;

const std::string LOG = "LOG";
const std::string SPACE = " ";

bool Logger::loggerOn = false;

void Logger::log(std::string message, std::string level) {
    if (loggerOn) {
        if(level == LoggerConstants::ERROR){
           cout << LOG << SPACE << level << SPACE << message << endl;
        }
    }
    return;
}

bool Logger::log(std::string message, std::string level, std::string logFilePath) {
    return false;
}
