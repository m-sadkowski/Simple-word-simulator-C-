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
}

Para Swiat::generujOrganizm() {
	while (true) {
		int X = rand() % (n - 2) + 1;
		int Y = rand() % (m - 2) + 1;
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
	/*
	this->dodajOrganizm(new Zolw(3, 3, this));
	this->dodajOrganizm(new WilczeJagody(2, 3, this));
	this->dodajOrganizm(new WilczeJagody(4, 3, this));
	this->dodajOrganizm(new WilczeJagody(3, 2, this));
	this->dodajOrganizm(new WilczeJagody(3, 4, this));
	*/
}

void Swiat::rysujSwiat() {
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << plansza[i][j];
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i]->getInicjatywa() == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		}
		else if (organizmy[i]->getSymbol() == 'C') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		}
		organizmy[i]->rysowanie();
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	int j = 0;
	for (int i = komunikaty.size() - 1; i >= 0; i--) {
		gotoxy(n + 1, 4 + j);
		j++;
		std::cout << komunikaty[i];
	}
	/*
	for (int i = 0; i < organizmy.size(); i++) {
		gotoxy(n + 1, m + 1 + i);
		std::cout << organizmy[i];
	}
	*/
	komunikaty.clear();
	gotoxy(n + 1, 1);
	std::cout << "Autor: Michal Sadkowski 197776";
	gotoxy(n + 1, 2);
	std::cout << "- 'q' aby zakonczyc";
	gotoxy(n + 1, 3);
	std::cout << "- 'z' aby zapisac gre";
}

void Swiat::wykonajTure(char strzalka) {
	if (!(strzalka == ARROW_UP || strzalka == ARROW_DOWN || strzalka == ARROW_LEFT || strzalka == ARROW_RIGHT || strzalka == 'm'))
	{
		return;
	}
	posortujOrganizmy();
	for (int i = 0; i < organizmy.size(); i++) {
		organizmy[i]->zwiekszWiek();
		if (organizmy[i]->getCooldown())
		{
			organizmy[i]->zmniejszCooldown();
		}
		//Sleep(100);
		//rysujSwiat();
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

void Swiat::zapiszSwiat()
{
	system("cls");
	std::cout << "Podaj nazwe pliku do zapisu: ";
	std::string nazwa_pliku;
	std::cin >> nazwa_pliku;
	nazwa_pliku += ".txt";
	std::ofstream plik(nazwa_pliku);
	bool czyCzlowiekZyje = false;
	Czlowiek* czlowiek = nullptr;
	plik << m << " " << n << std::endl;
	plik << organizmy.size() << std::endl;
	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i]->getSymbol() == 'C') {
			czyCzlowiekZyje = true;
			czlowiek = dynamic_cast<Czlowiek*>(organizmy[i]);
		}
		plik << organizmy[i]->getSymbol() << " " << organizmy[i]->getX() << " " << organizmy[i]->getY() << " " << organizmy[i]->getWiek() << " " << organizmy[i]->getSila() << " " << organizmy[i]->getInicjatywa() << " " << organizmy[i]->getCooldown() << std::endl;
	}
	if (czyCzlowiekZyje)
	{
		plik << czlowiek->getCzasMocy() << " " << czlowiek->getMocUzyta() << std::endl;
	}
	plik.close();
	std::cout << "Plik zostal zapisany." << std::endl;
	std::cout << "Nacisnij dowolny klawisz aby kontynuowac.";
}

void Swiat::kasujSwiat(std::ifstream& plik)
{
	int m, n;
	plik >> m >> n;
	delete[] plansza;
	plansza = new char* [m];
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
	this->m = m;
	this->n = n;
	for (int i = 0; i < organizmy.size(); i++) {
		delete organizmy[i];
	}
	organizmy.clear();
}

void Swiat::wczytajSwiat()
{
	system("cls");
	std::cout << "Podaj nazwe pliku do wczytania: ";
	std::string nazwa_pliku;
	std::cin >> nazwa_pliku;
	nazwa_pliku += ".txt";
	std::ifstream plik(nazwa_pliku);
	if (!plik.is_open()) {
		std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
		std::cout << "Nacisnij dowolny klawisz aby kontynuowac.";
		return;
	}
	kasujSwiat(plik);
	int ilosc;
	plik >> ilosc;
	for (int i = 0; i < ilosc; i++) {
		char symbol;
		int x, y, wiek, sila, inicjatywa, cooldown;
		plik >> symbol >> x >> y >> wiek >> sila >> inicjatywa >> cooldown;
		switch (symbol)
		{
			case 'A':
				dodajOrganizm(new Antylopa(x, y, this, wiek, sila, inicjatywa, cooldown));
				break;
			case 'b':
				dodajOrganizm(new BarszczSosnowskiego(x, y, this, wiek, sila, inicjatywa, cooldown));
				break;
			case 'C':
				dodajOrganizm(new Czlowiek(x, y, this, wiek, sila, inicjatywa, cooldown));
				break;
			case 'g':
				dodajOrganizm(new Guarana(x, y, this, wiek, sila, inicjatywa, cooldown));
				break;
			case 'L':
				dodajOrganizm(new Lis(x, y, this, wiek, sila, inicjatywa, cooldown));
				break;
			case 'm':
				dodajOrganizm(new Mlecz(x, y, this, wiek, sila, inicjatywa, cooldown));
				break;
			case 'O':
				dodajOrganizm(new Owca(x, y, this, wiek, sila, inicjatywa, cooldown));
				break;
			case 't':
				dodajOrganizm(new Trawa(x, y, this, wiek, sila, inicjatywa, cooldown));
				break;
			case 'w':
				dodajOrganizm(new WilczeJagody(x, y, this, wiek, sila, inicjatywa, cooldown));
				break;
			case 'W':
				dodajOrganizm(new Wilk(x, y, this, wiek, sila, inicjatywa, cooldown));
				break;
			case 'Z':
				dodajOrganizm(new Zolw(x, y, this, wiek, sila, inicjatywa, cooldown));
				break;
			default:
				break;
		}
	}
	int czasMocy, mocUzyta;
	plik >> czasMocy >> mocUzyta;
	for (int i = 0; i < organizmy.size(); i++)
	{
		if (organizmy[i]->getSymbol() == 'C')
		{
			Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(organizmy[i]);
			czlowiek->setCzasMocy(czasMocy);
			czlowiek->setMocUzyta(mocUzyta);
			break;
		}
	}
	plik.close();
}

Swiat::~Swiat() {
	for (int i = 0; i < m; i++) {
		delete[] plansza[i];
	}
	delete[] plansza;
}