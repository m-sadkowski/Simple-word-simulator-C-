#pragma once
#include"Zwierze.h"

class Antylopa : public Zwierze{

public:
	// KONSTRUKTOR
	Antylopa(int x, int y, Swiat* swiat) : Zwierze(4, 4, 'A', x, y, swiat) {}
	Antylopa(int x, int y, Swiat* swiat, int wiek, int sila, int inicjatywa, int cooldown) : Zwierze(x, y, swiat, 'A', wiek, sila, inicjatywa, cooldown) {}

	// METODY
	void akcja() override;
	void kolizja(Organizm* organizm) override;
	bool maSwojaKolizje() override { return true; }

	// DESTRUKTOR
	~Antylopa();
};