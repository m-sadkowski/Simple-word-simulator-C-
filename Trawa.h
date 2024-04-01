#pragma once
#include"Roslina.h"

class Trawa : public Roslina {

public:
	// KONSTRUKTOR
	Trawa(int x, int y, Swiat* swiat) : Roslina(0, 0, 't', x, y, swiat) {}
	Trawa(int x, int y, Swiat* swiat, int wiek, int sila, int inicjatywa, int cooldown) : Roslina(x, y, swiat, 't', wiek, sila, inicjatywa, cooldown) {}

	// DESTRUKTOR
	~Trawa();
};
