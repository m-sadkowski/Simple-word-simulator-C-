#pragma once
#include"Zwierze.h"

class Wilk : public Zwierze {

public:
	// KONSTRUKTOR
	Wilk(int x, int y, Swiat* swiat) : Zwierze(9, 5, 'W', x, y, swiat) {}

	// DESTRUKTOR
	~Wilk();
};