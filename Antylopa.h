#pragma once
#include"Zwierze.h"

class Antylopa : public Zwierze{

public:
	// KONSTRUKTOR
	Antylopa(int x, int y, Swiat* swiat) : Zwierze(4, 4, 'A', x, y, swiat) {}

	// METODY
	void akcja() override;
	void kolizja(Organizm* organizm) override;

	// DESTRUKTOR
	~Antylopa();
};