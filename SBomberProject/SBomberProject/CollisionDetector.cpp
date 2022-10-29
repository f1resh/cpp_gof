#include "CollisionDetector.h"

bool CollisionDetector::CheckPlaneAndLevelGUI(const Plane& plane, const LevelGUI& lgui)
{
    if (plane.GetX() > lgui.GetFinishX())
    {
        return true;
    }
    return false;
}

int16_t CollisionDetector::CheckBombsAndGround(const std::vector<DestroyableGroundObject*>& vecDestoyableObjects, std::vector<GameObject*>& vecStaticObjects,
    std::vector<DynamicObject*>& vecDynamicObj,
    const std::vector<Bomb*>& vecBombs, Ground& ground)
{
    const double y = ground.GetY();
    int16_t score{ 0 };
    for (size_t i = 0; i < vecBombs.size(); i++)
    {
        if (vecBombs[i]->GetY() >= y) // Пересечение бомбы с землей
        {
            ground.AddCrater(vecBombs[i]->GetX());
            score += CheckDestoyableObjects(vecDestoyableObjects, vecStaticObjects, vecBombs[i]);
            DeleteDynamicObj(vecDynamicObj, vecBombs[i]);
        }
    }
    return score;
}

int16_t CollisionDetector::CheckDestoyableObjects(const std::vector<DestroyableGroundObject*>& vecDestoyableObjects, 
     std::vector<GameObject*>& vecStaticObjects, Bomb* pBomb)
{
    const double size = pBomb->GetWidth();
    const double size_2 = size / 2;
    int16_t score{0};
    for (size_t i = 0; i < vecDestoyableObjects.size(); i++)
    {
        const double x1 = pBomb->GetX() - size_2;
        const double x2 = x1 + size;
        if (vecDestoyableObjects[i]->isInside(x1, x2))
        {
            score += vecDestoyableObjects[i]->GetScore();
            DeleteStaticObj(vecStaticObjects, vecDestoyableObjects[i]);
        }
    }
    return score;
}


void CollisionDetector::DeleteDynamicObj(std::vector<DynamicObject*>& vecDynamicObj,DynamicObject* pObj)
{
    auto it = vecDynamicObj.begin();
    for (; it != vecDynamicObj.end(); it++)
    {
        if (*it == pObj)
        {
            vecDynamicObj.erase(it);
            break;
        }
    }
}

void CollisionDetector::DeleteStaticObj(std::vector<GameObject*>& vecStaticObj, GameObject* pObj)
{
    auto it = vecStaticObj.begin();
    for (; it != vecStaticObj.end(); it++)
    {
        if (*it == pObj)
        {
            vecStaticObj.erase(it);
            break;
        }
    }
}