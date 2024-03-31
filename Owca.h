#pragma once
#include"Zwierze.h"

class Owca : public Zwierze {

public:
	// KONSTRUKTOR
	Owca(int x, int y, Swiat* swiat) : Zwierze(4, 4, 'O', x, y, swiat) {}

	// DESTRUKTOR
	~Owca();
};