#include<iostream>

#include"Swiat.h"
#include"Cursor.h"
#include"Czlowiek.h"

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