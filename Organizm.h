#pragma once
#include<string>

class Swiat;

class Organizm {
protected:
	int x, y;
	int sila;
	int inicjatywa;
	int wiek;
	char symbol;
	Swiat* swiat;
	int cooldown = 0;
public:
	// KONSTRUKTOR
	Organizm(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat);

	// METODY
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* organizm) = 0;
	void rysowanie();
	void zwiekszWiek() { wiek++; }
	void zmniejszCooldown() { cooldown--; }
	std::string nazwaOrganizmu(char symbol);

	// GETTERY
	const int getSila() { return sila; } const
	const int getInicjatywa() { return inicjatywa; } const
	const char getSymbol() { return symbol; } const
	const int getX() { return x; } const
	const int getY() { return y; } const
	const int getCooldown() { return cooldown; } const

	// SETTERY 
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setSila(int sila) { this->sila = sila; }
	void setCooldown(int cooldown) { this->cooldown = cooldown; }

	// DESTRUKTOR
	~Organizm();
};