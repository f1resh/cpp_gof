#include "LoggerSingleton.h"
#include <string>

using namespace std;


void __fastcall LoggerSingleton::OpenLog(const string& FN)
{
    FileLoggerSingleton::getInstance().OpenFileLog(FN);
}

void LoggerSingleton::CloseLog()
{
    FileLoggerSingleton::getInstance().CloseFileLog();
}

void __fastcall LoggerSingleton::WriteToLog(const string& str)
{
    FileLoggerSingleton::getInstance().WriteToLog(std::to_string(counter++) +" - "+ str);
}

void __fastcall LoggerSingleton::WriteToLog(const string& str, int n)
{
    FileLoggerSingleton::getInstance().WriteToLog(std::to_string(counter++) + " - " + str, n);
}

void __fastcall LoggerSingleton::WriteToLog(const string& str, double d)
{
    FileLoggerSingleton::getInstance().WriteToLog(std::to_string(counter++) + " - " + str, d);
}

