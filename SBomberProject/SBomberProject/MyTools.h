#pragma once

#include <stdint.h>
#include <string>

namespace MyTools {

	//=============================================================================================

	void __fastcall OpenLogFile(const std::string& FN);

	void CloseLogFile();

	void __fastcall WriteToLog(const std::string& str);

	void __fastcall WriteToLog(const std::string& str, int n);

	void __fastcall WriteToLog(const std::string& str, double d);

	int __fastcall RandomNumberTo(int);

	//=============================================================================================

};