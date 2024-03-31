#include<iostream>
#include<cstdlib>
#include<string>

#include"Zwierze.h"
#include"Swiat.h"

using namespace std;

void Zwierze::akcja() {
	int ruch = rand() % 4;
	int newX = this->getX();
	int newY = this->getY();
	switch (ruch)
	{
		case 0:
			newY--;
			break;
		case 1:
			newX++;
			break;
		case 2:
			newY++;
			break;
		case 3:
			newX--;
			break;
	}

	if (newX <= 0 || newX >= swiat->getSzerokosc() - 1 || newY <= 0 || newY >= swiat->getWysokosc() - 1) {
		Zwierze::akcja();
		return;
	}

	if (swiat->getOrganizm(newX, newY) == nullptr) {
		this->setX(newX);
		this->setY(newY);
	}
	else if (newX != this->getX() || newY != this->getY()) {
		this->kolizja(swiat->getOrganizm(newX, newY));
	}
}

void Zwierze::kolizja(Organizm* organizm) {
	if (organizm->getSymbol() == this->getSymbol()) {
		std::string komunikat = std::string(1, symbol) + " na pozycji: " + std::to_string(x + 1) + ", " + std::to_string(y);
		Organizm* nowy = new Zwierze(this->sila, this->inicjatywa, this->symbol, this->x + 1, this->y, this->swiat);
		swiat->dodajOrganizm(nowy);
		komunikat = "Rozmnozenie: " + komunikat;
		swiat->dodajKomunikat(komunikat);
	}
	else {
		std::string komunikat = std::string(1, symbol) + " na pozycji (" + std::to_string(x) + ", " + std::to_string(y) + ")";
		if (organizm->getSila() > this->getSila()) {
			komunikat = komunikat + " zostal zabity przez " + organizm->getSymbol();
			swiat->usunOrganizm(this);
		}
		else {
			if (organizm->getSymbol() == 'Z' && this->getSila() < 5) {
				komunikat = komunikat + " zostal odparty przez " + organizm->getSymbol();
			}
			else if (organizm->getSymbol() == 'A')
			{
				if (rand() % 2 == 0)
				{
					swiat->dodajKomunikat("Antylopa ucieka");
				}
				else
				{
					komunikat = komunikat + " zabil " + organizm->getSymbol();
					swiat->usunOrganizm(organizm);
					swiat->przeniesOrganizm(this, organizm->getX(), organizm->getY());
				}
			}
			else {
				komunikat = komunikat + " zabil " + organizm->getSymbol();
				swiat->usunOrganizm(organizm);
				swiat->przeniesOrganizm(this, organizm->getX(), organizm->getY());
			}
		}
		swiat->dodajKomunikat(komunikat);
	}
}

Zwierze::~Zwierze() {}