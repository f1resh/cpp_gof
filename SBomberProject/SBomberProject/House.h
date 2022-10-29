#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"
#include "ScreenSingleton.h"

class House : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;
	
	friend class HouseBuilderA;

private:
	char look[7][14] = {{' '}};
	const uint16_t score = 40;
	ConsoleColor color = ConsoleColor::CC_LightMagenta;
};

