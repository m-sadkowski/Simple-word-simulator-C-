#include<iostream>

#include"Swiat.h"
#include"Cursor.h"

#include"Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Zolw.h"
#include "Lis.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"

Swiat::Swiat(int m, int n) {
	this->m = m;
	this->n = n;
	plansza = new char*[m];
	for (int i = 0; i < m; i++) {
		plansza[i] = new char[n];
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
				plansza[i][j] = '#';
			}
			else {
				plansza[i][j] = '.';
			}
		}
	}
	generujSwiat();
}

Para Swiat::generujOrganizm() {
	while (true) {
		int X = rand() % (m - 2) + 1;
		int Y = rand() % (n - 2) + 1;
		if (getOrganizm(X, Y) == nullptr)
		{
			return Para(X, Y);
		}
	}
}

void Swiat::generujSwiat() {
	int maxOrganizmow = (m + n) / 11;
	int ilosc = rand() % maxOrganizmow + 1;
	for (int j = 0; j < ilosc; j++) {
		Para para = generujOrganizm();
		this->dodajOrganizm(new Owca(para.x, para.y, this));
	}
	ilosc = rand() % maxOrganizmow + 1;
	for (int j = 0; j < ilosc; j++) {
		Para para = generujOrganizm();
		this->dodajOrganizm(new Wilk(para.x, para.y, this));
	}
	ilosc = rand() % maxOrganizmow + 1;
	for (int j = 0; j < ilosc; j++) {
		Para para = generujOrganizm();
		this->dodajOrganizm(new Zolw(para.x, para.y, this));
	}
	ilosc = rand() % maxOrganizmow + 1;
	for (int j = 0; j < ilosc; j++) {
		Para para = generujOrganizm();
		this->dodajOrganizm(new Lis(para.x, para.y, this));
	}
	ilosc = rand() % maxOrganizmow + 1;
	for (int j = 0; j < ilosc; j++) {
		Para para = generujOrganizm();
		this->dodajOrganizm(new Antylopa(para.x, para.y, this));
	}
	ilosc = rand() % maxOrganizmow + 1;
	for (int j = 0; j < ilosc; j++) {
		Para para = generujOrganizm();
		this->dodajOrganizm(new Trawa(para.x, para.y, this));
	}
	ilosc = rand() % maxOrganizmow + 1;
	for (int j = 0; j < ilosc; j++) {
		Para para = generujOrganizm();
		this->dodajOrganizm(new Mlecz(para.x, para.y, this));
	}
	ilosc = rand() % maxOrganizmow + 1;
	for (int j = 0; j < ilosc; j++) {
		Para para = generujOrganizm();
		this->dodajOrganizm(new Guarana(para.x, para.y, this));
	}
	ilosc = rand() % maxOrganizmow + 1;
	for (int j = 0; j < ilosc; j++) {
		Para para = generujOrganizm();
		this->dodajOrganizm(new WilczeJagody(para.x, para.y, this));
	}
	ilosc = rand() % maxOrganizmow + 1;
	for (int j = 0; j < ilosc; j++) {
		Para para = generujOrganizm();
		this->dodajOrganizm(new BarszczSosnowskiego(para.x, para.y, this));
	}
	ilosc = rand() % maxOrganizmow + 1;
	for (int j = 0; j < ilosc; j++) {
		Para para = generujOrganizm();
		this->dodajOrganizm(new Owca(para.x, para.y, this));
	}
	Para para = generujOrganizm();
	this->dodajOrganizm(new Czlowiek(para.x, para.y, this));
}

void Swiat::rysujSwiat() {
	system("cls");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << plansza[i][j];
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < organizmy.size(); i++) {
		organizmy[i]->rysowanie();
	}
	for (int i = 0; i < komunikaty.size(); i++) {
		gotoxy(n + 1, 3 + i);
		std::cout << komunikaty[i];
	}
	komunikaty.clear();
	gotoxy(n + 1, 1);
	std::cout << "Autor: Michal Sadkowski 197776";
	gotoxy(n + 1, 2);
	std::cout << "'q' aby zakonczyc";
}

void Swiat::wykonajTure(char strzalka) {
	posortujOrganizmy();
	for (int i = 0; i < organizmy.size(); i++) {
		organizmy[i]->zwiekszWiek();
		if (organizmy[i]->getSymbol() == 'C') {
			Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(organizmy[i]);
			czlowiek->akcja(strzalka);
		}
		else
		{
			organizmy[i]->akcja();
		}
	}
}

void Swiat::dodajOrganizm(Organizm* organizm) {
	organizmy.push_back(organizm);
}

void Swiat::usunOrganizm(Organizm* organizm) {
	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i] == organizm) {
			organizmy.erase(organizmy.begin() + i);
			break;
		}
	}
}

void Swiat::przeniesOrganizm(Organizm* organizm, int x, int y) {
	organizm->setX(x);
	organizm->setY(y);
}

Organizm* Swiat::getOrganizm(int x, int y) {
	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i]->getX() == x && organizmy[i]->getY() == y) {
			return organizmy[i];
		}
	}
	return nullptr;
}

void Swiat::posortujOrganizmy()
{
	for (int i = 0; i < organizmy.size(); i++) {
		for (int j = 0; j < organizmy.size() - 1; j++) {
			if (organizmy[j]->getInicjatywa() < organizmy[j + 1]->getInicjatywa()) {
				Organizm* temp = organizmy[j];
				organizmy[j] = organizmy[j + 1];
				organizmy[j + 1] = temp;
			}
		}
	}
}

Swiat::~Swiat() {
	for (int i = 0; i < m; i++) {
		delete[] plansza[i];
	}
	delete[] plansza;
}