#pragma once
#include "Organizm.h"

class Swiat {
	int m, n;
	char** plansza;
public:
	Swiat(int m, int n);
	void wykonajTure(char strzalka);
	void rysujSwiat();
};