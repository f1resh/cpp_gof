#pragma once

#include <new>

#include "DestroyableGroundObject.h"
#include "Tree.h"

class TreeCreator {
public:
	virtual ~TreeCreator() {}
	virtual DestroyableGroundObject* Create() const = 0;
};

class TreeCreatorA : public TreeCreator {
public:
	DestroyableGroundObject* Create() const override{
		return new (std::nothrow) TreeA;
	}
};

class TreeCreatorB : public TreeCreator {
public:
	DestroyableGroundObject* Create() const override{
		return new (std::nothrow) TreeB;
	}
};