#include "Log.h"
#include <iostream>

void Log::logInfo(std::string info) {
	infoLog->log(info);
}

void Log::logWarning(std::string info) {
	warnLog->log(info);
}

void Log::logError(std::string info) {
	errorLog->log(info);
}

void Log::createLoggers() {
	infoLog = new Log("[INFO] ");
	warnLog = new Log("[WARNING] ");
	errorLog = new Log("[ERROR] ");
}

void Log::destroyLoggers() {
	delete infoLog;
	delete warnLog;
	delete errorLog;
}

Log::Log(std::string start) : start(start) {
	
}

void Log::log(std::string info) {
	std::cout << start << info << '\n';
}

Log* Log::infoLog = nullptr;
Log* Log::warnLog = nullptr;
Log* Log::errorLog = nullptr;
