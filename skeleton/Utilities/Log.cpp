#include "Log.h"
#include <iostream>

void Logger::logInfo(std::string info) {
	infoLog->log(info);
}

void Logger::logWarning(std::string info) {
	warnLog->log(info);
}

void Logger::logError(std::string info) {
	errorLog->log(info);
}

void Logger::createLoggers() {
	infoLog = new Logger("[INFO] ");
	warnLog = new Logger("[WARNING] ");
	errorLog = new Logger("[ERROR] ");
}

void Logger::destroyLoggers() {
	delete infoLog;
	delete warnLog;
	delete errorLog;
}

Logger::Logger(std::string start) : start(start) {
	
}

void Logger::log(std::string info) {
	std::cout << start << info << '\n';
}

Logger* Logger::infoLog = nullptr;
Logger* Logger::warnLog = nullptr;
Logger* Logger::errorLog = nullptr;
