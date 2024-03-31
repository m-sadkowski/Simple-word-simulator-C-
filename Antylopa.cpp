#include<cstdlib>

#include"Antylopa.h"
#include"Swiat.h"

void Antylopa::akcja() {
	int ruch = rand() % 4;
	int newX = this->getX();
	int newY = this->getY();
	switch (ruch)
	{
	case 0:
		newY--;
		newY--;
		break;
	case 1:
		newX++;
		newX++;
		break;
	case 2:
		newY++;
		newY++;
		break;
	case 3:
		newX--;
		newX--;
		break;
	}

	if (newX <= 0 || newX >= swiat->getSzerokosc() - 1 || newY <= 0 || newY >= swiat->getWysokosc() - 1) {
		Antylopa::akcja();
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

void Antylopa::kolizja(Organizm* organizm) {
	if (organizm->getSymbol() == 'A') {
		Zwierze::kolizja(organizm);
	}
	else if (rand() % 2 ? 0 : 1) {
		Zwierze::kolizja(organizm);
	}
	else
	{
		swiat->dodajKomunikat("Antylopa ucieka przed " + std::string(1, organizm->getSymbol()));
		Antylopa::akcja();
	}
}