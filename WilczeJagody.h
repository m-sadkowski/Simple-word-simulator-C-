#pragma once
#include"Roslina.h"

class WilczeJagody : public Roslina {

public:
	// KONSTRUKTOR
	WilczeJagody(int x, int y, Swiat* swiat) : Roslina(99, 0, 'w', x, y, swiat) {}
	WilczeJagody(int x, int y, Swiat* swiat, int wiek, int sila, int inicjatywa, int cooldown) : Roslina(x, y, swiat, 'w', wiek, sila, inicjatywa, cooldown) {}

	// METODY
	void kolizja(Organizm* organizm) override;
	bool maSwojaKolizje() override { return true; }

	// DESTRUKTOR
	~WilczeJagody();
};