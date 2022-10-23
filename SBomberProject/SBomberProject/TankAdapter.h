#pragma once

#include "DestroyableGroundObject.h"
#include "TankAdaptee.h"

class TankAdapter : public DestroyableGroundObject {
private:
	TankAdaptee tank;
public:
	TankAdapter() {}
	~TankAdapter() {}
	void SetPos(double nx, double ny) override;
	uint16_t GetWidth() const override;
	void SetWidth(uint16_t widthN) override;
	void Draw() const override;
	bool __fastcall isInside(double x1, double x2) const override;
	uint16_t GetScore() const override;
};