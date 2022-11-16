#pragma once

//#include "GameObject.h"
#include "LevelGUI.h"
#include <string>

class Mediator
{
private:
	LevelGUI* pLevelGUI;
public:
	Mediator(LevelGUI* plevelGUI_) : pLevelGUI(plevelGUI_) {}
	void Notify(const GameObject*, const std::string);
};

