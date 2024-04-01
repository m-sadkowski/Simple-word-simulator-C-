#pragma once
#include"Zwierze.h"

class Zolw : public Zwierze {

public:
	// KONSTRUKTOR
	Zolw(int x, int y, Swiat* swiat) : Zwierze(2, 1, 'Z', x, y, swiat) {}
	Zolw(int x, int y, Swiat* swiat, int wiek, int sila, int inicjatywa, int cooldown) : Zwierze(x, y, swiat, 'Z', wiek, sila, inicjatywa, cooldown) {}

	// METODY
	void akcja() override;
	void kolizja(Organizm* organizm) override;

	// DESTRUKTOR
	~Zolw();
};