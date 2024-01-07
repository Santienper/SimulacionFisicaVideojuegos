#pragma once
#include <string>

// Clase incluida para abstraer la escritura a consola
// por si da tiempo a cambiar a una forma mejor de hacerlo.

class Log {
public:
	static void logInfo(std::string);
	static void logWarning(std::string);
	static void logError(std::string);

	static void createLoggers();
	static void destroyLoggers();
private:
	static Log* infoLog, * warnLog, * errorLog;

	Log(std::string start);
	void log(std::string);
	std::string start;
};
