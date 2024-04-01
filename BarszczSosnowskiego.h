#pragma once
#include"Roslina.h"

class BarszczSosnowskiego : public Roslina {

public:
	// KONSTRUKTOR
	BarszczSosnowskiego(int x, int y, Swiat* swiat) : Roslina(10, 0, 'b', x, y, swiat) {}
	BarszczSosnowskiego(int x, int y, Swiat* swiat, int wiek, int sila, int inicjatywa, int cooldown) : Roslina(x, y, swiat, 'b', wiek, sila, inicjatywa, cooldown) {}

	// METODY
	void kolizja(Organizm* organizm) override;
	void akcja() override;

	// DESTRUKTOR
	~BarszczSosnowskiego();
};