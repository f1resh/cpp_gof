
#include <iostream>

#include "Bomb.h"
#include "ScreenSingleton.h"

using namespace std;

void Bomb::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_LightMagenta);
    ScreenSingleton::getInstance().GotoXY(x, y);
    cout << "*";
}