#pragma once
#pragma once
#include"Roslina.h"

class BarszczSosnowskiego : public Roslina {

public:
	// KONSTRUKTOR
	BarszczSosnowskiego(int x, int y, Swiat* swiat) : Roslina(10, 0, 'b', x, y, swiat) {}

	// METODY
	void kolizja(Organizm* organizm) override;
	void akcja() override;

	// DESTRUKTOR
	~BarszczSosnowskiego();
};