#include"Antylopa.h"
#include"Swiat.h"
#include"Roslina.h"

void Antylopa::akcja() {
	int ruch = rand() % 4;
	int newX = this->getX();
	int newY = this->getY();
	switch (ruch)
	{
	case 0:
		newY-=2;
		break;
	case 1:
		newX+=2;
		break;
	case 2:
		newY+=2;
		break;
	case 3:
		newX-=2;
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
	if (organizm->getSila() > this->getSila())
	{
		if (rand() % 2 ? 1 : 0)
		{
			std::string komunikat = this->nazwaOrganizmu(this->getSymbol()) + " ucieka przed " + organizm->nazwaOrganizmu(organizm->getSymbol());
			swiat->dodajKomunikat(komunikat);
			this->akcja();
		}
		else
		{
			std::string komunikat = organizm->nazwaOrganizmu(organizm->getSymbol()) + " zabija " + this->nazwaOrganizmu(this->getSymbol());
			swiat->dodajKomunikat(komunikat);
			swiat->przeniesOrganizm(organizm, this->getX(), this->getY());
			swiat->usunOrganizm(this);
		}
	}
	else
	{
		this->Zwierze::kolizja(organizm);
	}
	return;
}