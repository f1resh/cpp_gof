
#include <iostream>

#include "House.h"
#include "ScreenSingleton.h"

using namespace std;

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

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

	return false;
}

void House::Draw() const
{

	ScreenSingleton::getInstance().SetColor(color);
	for (int i = 6; i >=0; --i)
	{
		ScreenSingleton::getInstance().GotoXY(x, y - i);
		cout << look[i];
		//for (size_t j = 0; j < 14; j++)
		//{
		//	cout << look[i][j];
		//}
		
	}
}