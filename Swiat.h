#pragma once
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<fstream>
#include<conio.h>

#include"Organizm.h"

struct Para {
	int x;
	int y;
	Para(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class Swiat {
	int m, n;
	char** plansza;
	std::vector<Organizm*> organizmy;
	std::vector<std::string> komunikaty;
public:
	// KONSTRUKTOR
	Swiat(int m, int n);

	// METODY
	void generujSwiat();
	Para generujOrganizm();
	void wykonajTure(char strzalka);
	void rysujSwiat();
	void dodajOrganizm(Organizm* organizm);
	void usunOrganizm(Organizm* organizm);
	void przeniesOrganizm(Organizm* organizm, int x, int y);
	void posortujOrganizmy();
	void dodajKomunikat(std::string komunikat) { komunikaty.push_back(komunikat); }
	void zapiszSwiat();
	void wczytajSwiat();

	// GETTERY
	const int getWysokosc() { return m; }
	const int getSzerokosc() { return n; }
	const size_t getIloscOrganizmow() { return organizmy.size(); }
	Organizm* getOrganizm(int x, int y);

	// DESTRUKTOR 
	~Swiat();
};