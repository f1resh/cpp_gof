#pragma once
#include "DynamicObject.h"
#include "Bomb.h"

class BombDecorator : public DynamicObject {
private:
	Bomb bomb;
public:
	BombDecorator() {};
	~BombDecorator() {};
	void Draw() const override;
	void Move(uint16_t time) override;
	void SetPos(double nx, double ny) override;
	uint16_t GetWidth() const override;
	void SetWidth(uint16_t widthN) override;
	double GetY() const;
	double GetX() const;

	void SetDirection(double dx, double dy);
	void SetSpeed(double sp);
	void SetPos(int x, int y);
	void SetWidth(int crater_size);
};
