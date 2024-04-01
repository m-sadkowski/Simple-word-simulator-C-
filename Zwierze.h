#pragma once
#include "Organizm.h"

class Swiat;

class Zwierze : public Organizm {
public:
	// KONSTRUKTOR
	Zwierze(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat) : Organizm(sila, inicjatywa, symbol, x, y, swiat) {}
	Zwierze(int x, int y, Swiat* swiat, char symbol, int wiek, int sila, int inicjatywa, int cooldown) : Organizm(x, y, swiat, symbol, wiek, sila, inicjatywa, cooldown) {}

	// METODY
	void akcja() override;
	void kolizja(Organizm* organizm) override;

	// DESTRUKTOR
	~Zwierze();
};