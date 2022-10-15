#pragma once
#include <stdint.h>
#include <string>
#include <fstream>

using namespace std;


class FileLoggerSingleton
{
private:
    ofstream logOut;

    FileLoggerSingleton() { }
    FileLoggerSingleton(const FileLoggerSingleton& root) = delete;
    FileLoggerSingleton& operator=(const FileLoggerSingleton&) = delete;

public:

    static FileLoggerSingleton& getInstance()
    {
        static FileLoggerSingleton theInstance;
        return theInstance;
    }

    string GetCurDateTime();
    void __fastcall OpenLog(const std::string& FN);
    void CloseLog();
    void __fastcall WriteToLog(const std::string& str);
    void __fastcall WriteToLog(const std::string& str, int n);
    void __fastcall WriteToLog(const std::string& str, double d);
};

