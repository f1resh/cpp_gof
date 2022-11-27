#pragma once
#include <string>
#include <fstream>
#include <chrono>

class FileLogger {
private:
	std::ofstream fileOut_;
	std::string GetCurDateTime();
public:
	FileLogger();
	~FileLogger();
	void Write(const std::string&);
	void Write(const std::string&, int);
	void Write(const std::string&, double);
};

extern FileLogger fileLogger;
