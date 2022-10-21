#pragma once
#include "BombDecorator.h"
#include "ScreenSingleton.h"
#include <iostream>

void BombDecorator::Move(uint16_t time) {
	bomb.Move(time * 1.4);
}

void BombDecorator::Draw() const {
	bomb.Draw();
	ScreenSingleton::getInstance().GotoXY(bomb.GetX(), bomb.GetY() - 1);
	std::cout << "|";
}

void BombDecorator::SetPos(double nx, double ny) {
	bomb.SetPos(nx, ny); 
}

uint16_t BombDecorator::GetWidth() const {
	return bomb.GetWidth();
}

void BombDecorator::SetWidth(uint16_t widthN) {
	bomb.SetWidth(widthN);
}

double BombDecorator::GetY() const {
	return bomb.GetY();
}

double BombDecorator::GetX() const {
	return bomb.GetX();
}

void BombDecorator::SetDirection(double dx, double dy) {
	bomb.SetDirection(dx, dy);
};
void BombDecorator::SetSpeed(double sp) {
	bomb.SetSpeed(sp);
};
void BombDecorator::SetPos(int x, int y) {
	bomb.SetPos(x, y);
};
void BombDecorator::SetWidth(int crater_size) {
	bomb.SetWidth(crater_size);
};


