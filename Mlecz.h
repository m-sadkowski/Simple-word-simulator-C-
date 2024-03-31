#pragma once
#include"Roslina.h"

class Mlecz : public Roslina {

public:
	// KONSTRUKTOR
	Mlecz(int x, int y, Swiat* swiat) : Roslina(0, 0, 'm', x, y, swiat) {}

	// METODY
	void akcja() override;

	// DESTRUKTOR
	~Mlecz();
};