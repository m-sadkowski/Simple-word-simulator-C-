#pragma once
#include"Roslina.h"

class Mlecz : public Roslina {

public:
	// KONSTRUKTOR
	Mlecz(int x, int y, Swiat* swiat) : Roslina(0, 0, 'm', x, y, swiat) {}
	Mlecz(int x, int y, Swiat* swiat, int wiek, int sila, int inicjatywa, int cooldown) : Roslina(x, y, swiat, 'm', wiek, sila, inicjatywa, cooldown) {}

	// METODY
	void akcja() override;

	// DESTRUKTOR
	~Mlecz();
};