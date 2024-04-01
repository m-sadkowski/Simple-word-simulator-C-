#pragma once
#include"Zwierze.h"

class Owca : public Zwierze {

public:
	// KONSTRUKTOR
	Owca(int x, int y, Swiat* swiat) : Zwierze(4, 4, 'O', x, y, swiat) {}
	Owca(int x, int y, Swiat* swiat, int wiek, int sila, int inicjatywa, int cooldown) : Zwierze(x, y, swiat, 'O', wiek, sila, inicjatywa, cooldown) {}

	// DESTRUKTOR
	~Owca();
};