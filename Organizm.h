#pragma once
#include"Swiat.h"

class Organizm {
	int sila;
	int inicjatywa;
	int wiek;
	struct polozenie {
		int x;
		int y;
	};
	polozenie polozenie;
public:
	void akcja();
	void kolizja();
	void rysowanie();
};