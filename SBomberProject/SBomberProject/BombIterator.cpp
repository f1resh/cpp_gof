#pragma once
#include "BombIterator.h"

void BombIterator::reset() {
	index = -1; 
	ptr = nullptr; 
}

BombIterator& BombIterator::operator++() {
	index++;

	for (; index < refVec.size(); ++index) {
		if (dynamic_cast<Bomb*>(refVec[index]) != nullptr) {
			ptr = dynamic_cast<Bomb*>(refVec[index]);
			break;
		}
	}

	if (index == refVec.size()) {
		index = -1;
		ptr = nullptr;
	}

	return *this;
}

BombIterator& BombIterator::operator--() {

	if (index == -1)
		index = refVec.size() - 1;

	for (; index >= 0; index--)
	{
		if (dynamic_cast<Bomb*>(refVec[index]) != nullptr)
		{
			ptr = dynamic_cast<Bomb*>(refVec[index]);
			break;
		}
	}
	if (index == -1)
	{
		ptr = nullptr;
	}
	return *this;


}

Bomb* BombIterator::operator*() {
	return dynamic_cast<Bomb*>(refVec.at(index));
};

bool BombIterator::operator==(BombIterator it) {
	if (index == it.index &&
		ptr == it.ptr &&
		refVec == it.refVec)
	{
		return true;
	}
	return false;

};

bool BombIterator::operator!=(BombIterator it) {
	return !(*this == it);
};

