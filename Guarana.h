#pragma once
#include"Roslina.h"

class Guarana : public Roslina {

public:
	// KONSTRUKTOR
	Guarana(int x, int y, Swiat* swiat) : Roslina(0, 0, 'g', x, y, swiat) {}

	// METODY
	void kolizja(Organizm* organizm) override;

	// DESTRUKTOR
	~Guarana();
};