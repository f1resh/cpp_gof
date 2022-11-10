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

void Bomb::AddObserver(DestroyableGroundObject* object)
{
    obsList.push_back(object);
}

void Bomb::RemoveObserver(DestroyableGroundObject* object)
{
    obsList.remove(object);
}

DestroyableGroundObject* Bomb::CheckDestoyableObjects()
{

    const double size = this->GetWidth();
    const double x1 = this->GetX() - (size / 2);
    const double x2 = x1 + size;

    for (const auto obj : obsList) {
        if (obj->HandleInsideCheck(x1, x2)) {
            return obj;
        }
    }
    return nullptr;
}