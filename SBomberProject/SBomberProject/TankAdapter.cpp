#pragma once
#include "TankAdapter.h"

void TankAdapter::SetPos(double nx, double ny)
{
	tank.SetPos(nx, ny);
}
uint16_t TankAdapter::GetWidth() const
{
	return tank.GetWidth();
}
void TankAdapter::Draw() const
{
	tank.Paint();
};
bool __fastcall TankAdapter::isInside(double x1, double x2) const
{
	return tank.isInRange(x1, x2);
};

void TankAdapter::SetWidth(uint16_t width) 
{
	tank.SetWidth(width);
}

uint16_t TankAdapter::GetScore() const 
{
	return tank.GetScore();
}