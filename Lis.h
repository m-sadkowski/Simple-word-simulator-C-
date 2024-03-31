#pragma once
#include"Zwierze.h"

class Lis : public Zwierze {

public:
	// KONSTRUKTOR
	Lis(int x, int y, Swiat* swiat) : Zwierze(3, 7, 'L', x, y, swiat) {}

	// METODY
	void akcja() override;

	// DESTRUKTOR
	~Lis();
};
