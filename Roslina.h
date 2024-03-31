#pragma once
#include "Organizm.h"

class Swiat;

class Roslina : public Organizm {

public:
	// KONSTRUKTOR
	Roslina(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat) : Organizm(sila, 0, symbol, x, y, swiat) {}

	// METODY
	void akcja() override;
	void kolizja(Organizm* organizm) override;

	// DESTRUKTOR
	~Roslina();
};