#include<iostream>

#include"Organizm.h"
#include"Cursor.h"

Organizm::Organizm(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat)
	: sila(sila), inicjatywa(inicjatywa), symbol(symbol), x(x), y(y), swiat(swiat), wiek(0) {}

Organizm::~Organizm() {}

void Organizm::rysowanie()
{
	int x = this->getX();
	int y = this->getY();
	gotoxy(x, y);
	std::cout << symbol;
	gotoxy(0, 0);
}

