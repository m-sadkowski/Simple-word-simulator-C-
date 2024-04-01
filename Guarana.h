#pragma once
#include"Roslina.h"

class Guarana : public Roslina {

public:
	// KONSTRUKTOR
	Guarana(int x, int y, Swiat* swiat) : Roslina(0, 0, 'g', x, y, swiat) {}
	Guarana(int x, int y, Swiat* swiat, int wiek, int sila, int inicjatywa, int cooldown) : Roslina(x, y, swiat, 'g', wiek, sila, inicjatywa, cooldown) {}

	// METODY
	void kolizja(Organizm* organizm) override;
	bool maSwojaKolizje() override { return true; }

	// DESTRUKTOR
	~Guarana();
};