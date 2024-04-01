#pragma once
#include"Zwierze.h"


class Czlowiek : public Zwierze {
	const int stalaSila = 5;
	bool mocUzyta = false;
	int czasMocy = 0;
	int cooldown = 0;
public:
	Czlowiek(int x, int y, Swiat* swiat) : Zwierze(5, 4, 'C', x, y, swiat) {}
	Czlowiek(int x, int y, Swiat* swiat, int wiek, int sila, int inicjatywa, int cooldown) : Zwierze(x, y, swiat, 'C', wiek, sila, inicjatywa, cooldown) {}

	void akcja(char c);
	bool maSwojaKolizje() override { return false; }
	void aktywujMoc();
	~Czlowiek();
};