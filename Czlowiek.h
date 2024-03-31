#pragma once
#include <iostream>
#include"Zwierze.h"


class Czlowiek : public Zwierze {
	const int stalaSila = 5;
	bool mocUzyta = false;
	int czasMocy = 0;
	int cooldown = 0;
public:
	Czlowiek(int x, int y, Swiat* swiat) : Zwierze(5, 4, 'C', x, y, swiat) {}
	void akcja(char c);
	void kolizja(Organizm* organizm) override;
	void aktywujMoc();
	~Czlowiek();
};