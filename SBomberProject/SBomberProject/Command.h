#pragma once
#include <vector>

#include "DynamicObject.h"
#include "GameObject.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "FileLoggerSingleton.h"


class Command {
public:
	virtual ~Command() {}
	virtual void Execute() const = 0;
};

class DeleteDynamicObjectCommand : public Command {
private:
	std::vector<DynamicObject*>* _p_Vec;
	DynamicObject* _p_Obj;
public:
	DeleteDynamicObjectCommand(std::vector<DynamicObject*>& pVec, DynamicObject* pObj) : _p_Vec(&pVec), _p_Obj(pObj) {}

	void Execute() const override {
		auto it = _p_Vec->begin();
		for (; it != _p_Vec->end(); it++)
		{
			if (*it == _p_Obj)
			{
				_p_Vec->erase(it);
				break;
			}
		}
	
	}
};

class DeleteGameObjectCommand : public Command {
private:
	std::vector<GameObject*>* _p_Vec;
	GameObject* _p_Obj;
public:
	DeleteGameObjectCommand(std::vector<GameObject*>& pVec, GameObject* pObj) : _p_Vec(&pVec), _p_Obj(pObj) {}

	void Execute() const override {
		auto it = _p_Vec->begin();
		for (; it != _p_Vec->end(); it++)
		{
			if (*it == _p_Obj)
			{
				_p_Vec->erase(it);
				break;
			}
		}
	
	}
};

class DropBombCommand : public Command {
private:
	const Plane* _p_Plane;
	std::vector<DynamicObject*>* _p_Vec;
	uint16_t* _p_Bombs_Number;
	int16_t* _p_score;
	int _crater_size, _speed;
public:
	DropBombCommand(const Plane* p_Plane, std::vector<DynamicObject*>& p_Vec, uint16_t& p_Bombs_Number, int16_t& p_score) :
		_p_Plane(p_Plane), _p_Vec(&p_Vec), _p_Bombs_Number(&p_Bombs_Number), _p_score(&p_score) {};

	void SetParams(int speed, int crater_size) {
		_speed = speed > 0 ? speed : 2;
		_crater_size = crater_size > 0 ? crater_size : SMALL_CRATER_SIZE;
	}

	void Execute() const override {
		if (*_p_Bombs_Number > 0)
		{
			FileLoggerSingleton::getInstance().WriteToLog(string(__FUNCTION__) + " was invoked");

			double x = _p_Plane->GetX() + 4;
			double y = _p_Plane->GetY() + 2;

			Bomb* pBomb = new Bomb;
			pBomb->SetDirection(0.3, 1);
			pBomb->SetSpeed(_speed);
			pBomb->SetPos(x, y);
			pBomb->SetWidth(_crater_size);

			_p_Vec->push_back(pBomb);
			(*_p_Bombs_Number)--;
			*_p_score -= Bomb::BombCost;
		}

	}

};
