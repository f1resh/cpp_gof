#pragma once

#include "House.h"
#include "ScreenSingleton.h"

class HouseBuilder
{
public:
	virtual ~HouseBuilder() {};
	virtual void Reset() = 0;
	virtual void BuildFloor() = 0;
	virtual void BuildWalls() = 0;
	virtual void BuildRoof() = 0;
	virtual void BuildChimney() = 0;
	virtual void BuildBigWindow() = 0;
	virtual void BuildSmallWindow() = 0;
	virtual void SetColor(ConsoleColor) = 0;
};

class HouseBuilderA : public HouseBuilder {
private:
	House* house;
public:
	HouseBuilderA();
	~HouseBuilderA();
	void Reset() override;
	void BuildFloor() override;
	void BuildWalls() override;
	void BuildRoof() override;
	void BuildChimney() override;
	void BuildBigWindow() override;
	void BuildSmallWindow() override;
	void SetColor(ConsoleColor) override;
	House* GetHouse();
};

