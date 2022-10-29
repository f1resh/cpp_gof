#pragma once
#include "HouseBuilder.h"

class HouseDirector
{
private:
	HouseBuilder* _builder;

	void BuildMainObjects() {
		_builder->BuildFloor();
		_builder->BuildWalls();
		_builder->BuildRoof();
	}

public:
	void SetBuilder(HouseBuilder* builder) {
		_builder = builder;
	}

	void BuildSmallWindowHouse() {
		_builder->SetColor(CC_Brown);
		BuildMainObjects();
		_builder->BuildSmallWindow();
	}

	void BuildBigWindowHouse() {
		_builder->SetColor(CC_Yellow);
		BuildMainObjects();
		_builder->BuildBigWindow();
		_builder->BuildChimney();
	}

	void BuildUsualHouse() {
		_builder->SetColor(CC_Cyan);
		BuildMainObjects();
	}
};

