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
	if (organizm->getSymbol() == this->getSymbol()) {
		Zwierze::kolizja(organizm);
	}
	else if (organizm->getSila() > this->getSila()) {
		if (rand() % 2 ? 0 : 1) {
			std::string komunikat = "Antylopa ginie przez "; // KOMUNIKATY
			komunikat += organizm->nazwaOrganizmu(organizm->getSymbol());
			swiat->dodajKomunikat(komunikat);

			swiat->przeniesOrganizm(organizm, this->getX(), this->getY());
			swiat->usunOrganizm(this);
		}
		else {
			std::string komunikat = "Antylopa ucieka przed "; // KOMUNIKATY
			komunikat += organizm->nazwaOrganizmu(organizm->getSymbol());
			swiat->dodajKomunikat(komunikat);

			Antylopa::akcja();
		}
	}
	else {
		std::string komunikat = "Antylopa "; // KOMUNIKATY
		Roslina* roslina = dynamic_cast<Roslina*>(organizm);
		if (roslina) {
			komunikat += "zjada ";
		}
		else {
			komunikat += "zabija ";
		}
		komunikat += organizm->nazwaOrganizmu(organizm->getSymbol());
		swiat->dodajKomunikat(komunikat);

		swiat->przeniesOrganizm(this, organizm->getX(), organizm->getY());
		swiat->usunOrganizm(organizm);
	}
}