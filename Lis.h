#pragma once
#include"Zwierze.h"

class Lis : public Zwierze {

public:
	// KONSTRUKTOR
	Lis(int x, int y, Swiat* swiat) : Zwierze(3, 7, 'L', x, y, swiat) {}
	Lis(int x, int y, Swiat* swiat, int wiek, int sila, int inicjatywa, int cooldown) : Zwierze(x, y, swiat, 'L', wiek, sila, inicjatywa, cooldown) {}

	// METODY
	void akcja() override;

	// DESTRUKTOR
	~Lis();
};
