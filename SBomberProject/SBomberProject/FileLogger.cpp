#include "FileLogger.h"
#define fileName "log.txt"

FileLogger::FileLogger() {
    fileOut_.open(fileName, std::ios_base::out);
};

FileLogger::~FileLogger() {
	if (fileOut_.is_open()) {
		fileOut_.close();
	}
};

std::string FileLogger::GetCurDateTime()
{
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char buf[64] = { 0 };
    ctime_s(buf, 64, &time);
    buf[strlen(buf) - 1] = '\0';
    return std::string(buf);
}

void __fastcall FileLogger::Write(const std::string& str) {
	if (fileOut_.is_open()) {
		fileOut_ << GetCurDateTime() << " - " << str << std::endl;
	}
};

void __fastcall FileLogger::Write(const std::string& str, int n) {
    if (fileOut_.is_open()) {
        fileOut_ << GetCurDateTime() << " - " << str << n << std::endl;
    }
};


void __fastcall FileLogger::Write(const std::string& str, double d) {
    if (fileOut_.is_open()) {
        fileOut_ << GetCurDateTime() << " - " << str << d << std::endl;
    }
}

FileLogger fileLogger;