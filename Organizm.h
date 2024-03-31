#pragma once

class Swiat;

class Organizm {
protected:
	int x, y;
	int sila;
	int inicjatywa;
	int wiek;
	char symbol;
	Swiat* swiat;
public:
	// KONSTRUKTOR
	Organizm(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat);

	// METODY
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* organizm) = 0;
	void rysowanie();
	void zwiekszWiek() { wiek++; }

	// GETTERY
	const int getSila() { return sila; } const
	const int getInicjatywa() { return inicjatywa; } const
	const char getSymbol() { return symbol; } const
	const int getX() { return x; } const
	const int getY() { return y; } const

	// SETTERY 
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	// DESTRUKTOR
	~Organizm();
};