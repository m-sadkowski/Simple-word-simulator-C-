#pragma once
#include"Zwierze.h"

class Wilk : public Zwierze {

public:
	// KONSTRUKTOR
	Wilk(int x, int y, Swiat* swiat) : Zwierze(9, 5, 'W', x, y, swiat) {}
	Wilk(int x, int y, Swiat* swiat, int wiek, int sila, int inicjatywa, int cooldown) : Zwierze(x, y, swiat, 'W', wiek, sila, inicjatywa, cooldown) {}

	// DESTRUKTOR
	~Wilk();
};