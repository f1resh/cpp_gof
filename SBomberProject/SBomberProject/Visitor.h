#pragma once

//#include "Bomb.h"
//#include "Plane.h"

class Bomb;
class Plane;

class Visitor {
public:
	virtual void log(const Bomb& b) const = 0;
	virtual void log(const Plane& p) const = 0;
};


class LogVisitor : public Visitor {
public:
	void log(const Bomb& b) const override;
	void log(const Plane& p) const override;
};