#include <iostream>
#include "AbstractLevelGUI.h"
#include "ScreenSingleton.h"

using namespace std;

void __fastcall AbstractLevelGUI::SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew)
{
    passedTime = passedTimeNew;
    fps = fpsNew;
    bombsNumber = bombsNumberNew;
    score = scoreNew;
}
