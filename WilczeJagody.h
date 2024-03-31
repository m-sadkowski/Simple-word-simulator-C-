#pragma once
#include"Roslina.h"

class WilczeJagody : public Roslina {

public:
	// KONSTRUKTOR
	WilczeJagody(int x, int y, Swiat* swiat) : Roslina(99, 0, 'w', x, y, swiat) {}

	// METODY
	void kolizja(Organizm* organizm) override;

	// DESTRUKTOR
	~WilczeJagody();
};