#include "HouseBuilder.h"

#include <cstring>

HouseBuilderA::HouseBuilderA()
{
	Reset();
}

HouseBuilderA::~HouseBuilderA()
{
	delete house;
}

void HouseBuilderA::Reset()
{
	house = new House();
	
	//reset of look, can be refactored to function
	std::memset(house->look, ' ', sizeof(char) * 7 * 14);
	for (size_t i = 0; i < 7; i++)
	{
		house->look[i][13] = '\0';
	}
}

void HouseBuilderA::BuildFloor()
{
	for (size_t i = 0; i < 13; ++i)
	{
		house->look[0][i] = '#';
	}
}

void HouseBuilderA::BuildWalls()
{
	house->look[1][0] = '#';
	house->look[2][0] = '#';
	house->look[1][12] = '#';
	house->look[2][12] = '#';
}

void HouseBuilderA::BuildRoof()
{
	for (size_t i = 0; i < 13; ++i)
	{
		house->look[3][i] = '#';
	}
	house->look[4][0] = '#';
	house->look[4][1] = '#';
	house->look[4][11] = '#';
	house->look[4][12] = '#';
	for (size_t i = 2; i < 11; ++i)
	{
		house->look[5][i] = '#';
	}
}

void HouseBuilderA::BuildChimney()
{
	house->look[6][8] = '#';
	house->look[6][9] = '#';
}

void HouseBuilderA::BuildBigWindow()
{
	house->look[1][5] = '+';
	house->look[1][8] = '+';
						
	house->look[1][6] = '+';
	house->look[1][7] = '+';
	house->look[2][6] = '+';
	house->look[2][7] = '+';
					
	house->look[2][5] = '+';
	house->look[2][8] = '+';
}

void HouseBuilderA::BuildSmallWindow()
{
	house->look[1][7] = '+';
	house->look[1][8] = '+';
	house->look[2][7] = '+';
	house->look[2][8] = '+';
}

void HouseBuilderA::SetColor(ConsoleColor _color)
{
	house->color = _color;
}


House* HouseBuilderA::GetHouse()
{
	House* result = house;
	Reset();
	return result;
}
