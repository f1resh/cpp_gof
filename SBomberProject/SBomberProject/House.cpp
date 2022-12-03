
#include <iostream>

#include "House.h"
#include "ScreenSingleton.h"

using namespace std;

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x;
	const double XEnd = x + width;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	if (x1 == XBeg || x2 == XEnd) return true;

	return false;
}

void House::Draw() const
{
	ScreenSingleton::getInstance().SetColor(CC_Yellow);
	ScreenSingleton::getInstance().GotoXY(x, y - 5);
	cout << "  ########  ";
	ScreenSingleton::getInstance().GotoXY(x, y - 4);
	cout << "##        ##";
	ScreenSingleton::getInstance().GotoXY(x, y - 3);
	cout << "############";
	ScreenSingleton::getInstance().GotoXY(x, y - 2);
	cout << "#          #";
	ScreenSingleton::getInstance().GotoXY(x, y - 1);
	cout << "#          #";
	ScreenSingleton::getInstance().GotoXY(x, y);
	cout << "############";
}

DestroyableGroundObject* House::Clone() const
{
	return new House(*this);
}

House::House(const House& house) {
	this->width = house.width;
}