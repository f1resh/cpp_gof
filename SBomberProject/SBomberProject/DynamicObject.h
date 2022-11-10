#pragma once

#include <stdint.h>
#include <utility>

#include "GameObject.h"

class Visitor;

class DynamicObject : public GameObject 
{
public:
    DynamicObject() : speed(0.0), xDirection(0.0), yDirection(0) { }

    inline void SetSpeed(double sp) { speed = sp; }
    inline void SetDirection(double dx, double dy) { xDirection = dx; yDirection = dy; }
    
    virtual void Move(uint16_t time) { x += xDirection * speed * time * 0.001; y += yDirection * speed * time * 0.001; };

    virtual void Accept(const Visitor& v) = 0;

    double GetSpeed() const;
    std::pair<double,double> GetDirection() const;

protected:

    double speed;
    double xDirection, yDirection;

};
