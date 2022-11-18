
#include <iostream>

#include "Plane.h"
#include "ScreenSingleton.h"

using namespace std;

void Plane::Draw() const
{
    DrawBody();
    DrawWings();
    DrawTail();

}

void ColorPlane::DrawBody() const
{
    ScreenSingleton::getInstance().SetColor(CC_LightRed);
    ScreenSingleton::getInstance().GotoXY(x, y);
    cout << "=========>";
}

void ColorPlane::DrawWings() const
{
    ScreenSingleton::getInstance().SetColor(CC_Yellow);
    ScreenSingleton::getInstance().GotoXY(x + 3, y + 1);
    cout << "////";
    ScreenSingleton::getInstance().GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
}

void ColorPlane::DrawTail() const
{
    ScreenSingleton::getInstance().SetColor(CC_Magenta);
    ScreenSingleton::getInstance().GotoXY(x - 2, y - 1);
    cout << "===";
}

void BigPlane::DrawBody() const
{
    ScreenSingleton::getInstance().SetColor(CC_LightBlue);
    ScreenSingleton::getInstance().GotoXY(x, y);
    cout << "===========>";
}

void BigPlane::DrawWings() const
{
    ScreenSingleton::getInstance().SetColor(CC_LightBlue);
    ScreenSingleton::getInstance().GotoXY(x + 3, y + 1);
    cout << "/////";
    ScreenSingleton::getInstance().GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\\\";
}

void BigPlane::DrawTail() const
{
    ScreenSingleton::getInstance().SetColor(CC_LightBlue);
    ScreenSingleton::getInstance().GotoXY(x - 2, y - 1);
    cout << "====";
}
