#pragma once
#include"Zwierze.h"

class Zolw : public Zwierze {

public:
	// KONSTRUKTOR
	Zolw(int x, int y, Swiat* swiat) : Zwierze(2, 1, 'Z', x, y, swiat) {}

	// METODY
	void akcja() override;
	void kolizja(Organizm* organizm) override;

	// DESTRUKTOR
	~Zolw();
};