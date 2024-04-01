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
	Organizm(int x, int y, Swiat* swiat, char symbol, int wiek, int sila, int inicjatywa, int cooldown);

	// METODY
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* organizm) = 0;
	virtual bool maSwojaKolizje() = 0;
	void rysowanie();
	void zwiekszWiek() { wiek++; }
	void zmniejszCooldown() { cooldown--; }
	std::string nazwaOrganizmu(char symbol);

	// OPERATORY
	friend std::ostream& operator<<(std::ostream& out, Organizm* org);

	// GETTERY
	const int getSila() { return sila; } 
	const int getInicjatywa() { return inicjatywa; } 
	const char getSymbol() { return symbol; } 
	const int getX() { return x; } 
	const int getY() { return y; } 
	const int getWiek() { return wiek; } 
	const int getCooldown() { return cooldown; } 

	// SETTERY 
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setSila(int sila) { this->sila = sila; }
	void setCooldown(int cooldown) { this->cooldown = cooldown; }

	// DESTRUKTOR
	~Organizm();
};