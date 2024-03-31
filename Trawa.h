#pragma once
#include"Roslina.h"

class Trawa : public Roslina {

public:
	// KONSTRUKTOR
	Trawa(int x, int y, Swiat* swiat) : Roslina(0, 0, 't', x, y, swiat) {}

	// DESTRUKTOR
	~Trawa();
};
