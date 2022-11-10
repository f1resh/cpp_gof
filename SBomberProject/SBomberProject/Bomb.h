#pragma once

#include "DynamicObject.h"
#include "DestroyableGroundObject.h"
#include <list>
//#include "Visitor.h"

class Visitor;

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

	void Accept(const Visitor &v) override;

	void AddObserver(DestroyableGroundObject*);

	void RemoveObserver(DestroyableGroundObject*);

	DestroyableGroundObject* CheckDestoyableObjects();

private:

	std::list<DestroyableGroundObject*> obsList;

};

