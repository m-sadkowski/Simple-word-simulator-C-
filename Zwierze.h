#pragma once
#include "Organizm.h"

class Swiat;

class Zwierze : public Organizm {

public:
	// KONSTRUKTOR
	Zwierze(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat) : Organizm(sila, inicjatywa, symbol, x, y, swiat) {}

	// METODY
	void akcja() override;
	void kolizja(Organizm* organizm) override;

	// DESTRUKTOR
	~Zwierze();
};