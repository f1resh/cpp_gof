#pragma once

#include "Bomb.h"
#include "DynamicObject.h"
#include <vector>


class BombIterator {
private:
	std::vector<DynamicObject*>& refVec;
	int index;
	Bomb* ptr;
public:
	BombIterator(std::vector<DynamicObject*>& ref) : refVec(ref), index(-1), ptr(nullptr) { ++(*this); }

	void reset();
	BombIterator& operator++();
	BombIterator& operator--();
	Bomb* operator*();
	bool operator==(BombIterator it);
	bool operator!=(BombIterator it);

	
};