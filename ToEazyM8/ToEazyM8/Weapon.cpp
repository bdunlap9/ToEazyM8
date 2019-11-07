#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(int sleepTime, int capacity, int offsetY[], int offsetX[]){
	this->sleepTime = sleepTime;
	this->capacity = capacity;
	this->offsetY = offsetY;
	this->offsetX = offsetX;
}
