#pragma once

#include "DynamicObject.h"
//#include "Visitor.h"

class Visitor;

class Plane : public DynamicObject
{
public:

    void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

    void Accept(const Visitor &v) override;

private:

};

