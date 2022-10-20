#include "WinterFactory.h"
#include "Ground.h"
#include "House.h"
#include "Tank.h"
#include "ScreenSingleton.h"

using namespace std;


Ground* WinterFactory::CreateGround()
{
	return new (nothrow) WinterGround;
}
House* WinterFactory::CreateHouse()
{
	return new (nothrow) WinterHouse;
}
Tank* WinterFactory::CreateTank()
{
	return new (nothrow) WinterTank;
}
void WinterFactory::CreateLevel1(std::vector<GameObject*>& refStaticObjVec)
{
	const uint16_t maxX = ScreenSingleton::getInstance().GetMaxX();
	const uint16_t maxY = ScreenSingleton::getInstance().GetMaxY();
	const uint16_t offset = 3;
	const uint16_t width = maxX - 7;

	Ground* pGr = CreateGround();
	uint16_t groundY = maxY - 5;
	pGr->SetPos(offset + 1, groundY);
	pGr->SetWidth(width - 2);
	refStaticObjVec.push_back(pGr);

	Tank* pTank = CreateTank();
	pTank->SetWidth(13);
	pTank->SetPos(30, groundY - 1);
	refStaticObjVec.push_back(pTank);

	//pTank = CreateTank();
	//pTank->SetWidth(13);
	//pTank->SetPos(50, groundY - 1);
	//refStaticObjVec.push_back(pTank);

	House* pHouse = CreateHouse();
	pHouse->SetWidth(13);
	pHouse->SetPos(50, groundY - 1);
	refStaticObjVec.push_back(pHouse);
}
