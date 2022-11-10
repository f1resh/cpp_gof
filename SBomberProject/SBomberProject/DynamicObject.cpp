#include "DynamicObject.h"


double DynamicObject::GetSpeed() const
{
    return speed;
}

std::pair<double, double> DynamicObject::GetDirection() const
{
    return std::pair<double, double>(xDirection,yDirection);
}


