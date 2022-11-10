#include <iostream>

#include "Bomb.h"
#include "ScreenSingleton.h"
#include "Visitor.h"

using namespace std;

void Bomb::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_LightMagenta);
    ScreenSingleton::getInstance().GotoXY(x, y);
    cout << "*";
}

void __fastcall Bomb::Accept(const Visitor& v)
{
    v.log(*this);
}
