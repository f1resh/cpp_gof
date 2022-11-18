#pragma once

#include <stdint.h>
#include <string>

#include "DestroyableGroundObject.h"
#include "Mediator.h"

#define MAX_MESSAGES 5

class Tank : public DestroyableGroundObject
{
public:
	~Tank() {
		if (pMediator) pMediator->Notify(this, "I'm dead x_x");
	}

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	void SetMediator(Mediator*);
	void RemoveMediator();
	std::string GenerateMessage() const;

private:

	const uint16_t score = 30;
	Mediator* pMediator = nullptr;
	const std::string strArray[MAX_MESSAGES] = { "Hello, plane!","Go away, plane!", "Don't drop the bombs!", "Would you kindly fly away?","Planes must die" };


	
};

