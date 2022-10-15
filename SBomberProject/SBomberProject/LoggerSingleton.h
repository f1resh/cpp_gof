#pragma once
#include <string>
#include "FileLoggerSingleton.h"

class LoggerSingleton 
{
private:
    LoggerSingleton() { counter = 1; }
    LoggerSingleton(const LoggerSingleton& root) = delete;
    LoggerSingleton& operator=(const LoggerSingleton&) = delete;

    int counter;

public:

    static LoggerSingleton& getInstance()
    {
        static LoggerSingleton theInstance;
        return theInstance;
    }

    void __fastcall OpenLog(const std::string& FN);
    void CloseLog();
    void __fastcall WriteToLog(const std::string& str);
    void __fastcall WriteToLog(const std::string& str, int n);
    void __fastcall WriteToLog(const std::string& str, double d);
};

