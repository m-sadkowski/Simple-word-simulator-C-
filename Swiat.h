#pragma once
#include<iostream>
#include<vector>

#include"Organizm.h"

class Swiat {
	int m, n;
	char** plansza;
	std::vector<Organizm*> organizmy;
	std::vector<std::string> komunikaty;
public:
	// KONSTRUKTOR
	Swiat(int m, int n);

	// METODY
	void wykonajTure(char strzalka);
	void rysujSwiat();
	void dodajOrganizm(Organizm* organizm);
	void usunOrganizm(Organizm* organizm);
	void przeniesOrganizm(Organizm* organizm, int x, int y);
	void posortujOrganizmy();
	void dodajKomunikat(std::string komunikat) { komunikaty.push_back(komunikat); }

	// GETTERY
	const int getWysokosc() { return m; }
	const int getSzerokosc() { return n; }
	Organizm* getOrganizm(int x, int y);

	// DESTRUKTOR 
	~Swiat();
};