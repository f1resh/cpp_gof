#pragma once

#include "Plane.h"
#include "LevelGUI.h"
#include "Bomb.h"
#include "Ground.h"
#include "DestroyableGroundObject.h"
#include "DynamicObject.h"
#include "GameObject.h"

#include <vector>

class CollisionDetector
{
private:
	void DeleteDynamicObj(std::vector<DynamicObject*>& vecDynamicObj, DynamicObject* pObj);
	void DeleteStaticObj(std::vector<GameObject*>& vecStaticObj, GameObject* pObj);
public:
	~CollisionDetector() {}
	bool CheckPlaneAndLevelGUI(const Plane& plane, const LevelGUI& lgui);
	int16_t CheckBombsAndGround(const std::vector<DestroyableGroundObject*>& vecDestoyableObjects, std::vector<GameObject*>& vecStaticObjects,
		std::vector<DynamicObject*>& vecDynamicObj,
		const std::vector<Bomb*>& vecBombs, Ground& ground);
	int16_t __fastcall CheckDestoyableObjects(const std::vector<DestroyableGroundObject*>& vecDestoyableObjects,
		std::vector<GameObject*>& vecStaticObjects, Bomb* pBomb);
};

