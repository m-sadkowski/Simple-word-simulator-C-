#pragma once
#include "Organizm.h"

class Swiat;

class Roslina : public Organizm {

public:
	// KONSTRUKTOR
	Roslina(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat) : Organizm(sila, 0, symbol, x, y, swiat) {}
	Roslina(int x, int y, Swiat* swiat, char symbol, int wiek, int sila, int inicjatywa, int cooldown) : Organizm(x, y, swiat, symbol, wiek, sila, inicjatywa, cooldown) {}

	// METODY
	void akcja() override;
	void kolizja(Organizm* organizm) override;

	// DESTRUKTOR
	~Roslina();
};