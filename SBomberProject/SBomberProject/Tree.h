#pragma once

#include "DestroyableGroundObject.h"

class TreeA : public DestroyableGroundObject
{
private:
	const uint16_t score = 15;
public:
	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

};

class TreeB : public DestroyableGroundObject
{
private:
	const uint16_t score = 20;
public:
	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;
};