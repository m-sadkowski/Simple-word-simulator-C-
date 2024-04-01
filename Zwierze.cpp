#include"Cursor.h"
#include"Zwierze.h"
#include"Swiat.h"
#include"FabrykaZwierzat.h"
#include"Roslina.h"

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
	/*
	std::string komunikat = "";
	komunikat += this->nazwaOrganizmu(this->getSymbol());
	if (organizm->getSymbol() == this->getSymbol()) {
		if (organizm->getCooldown() == 0 && this->getCooldown() == 0)
		{
			Zwierze* nowy = FabrykaZwierzat::utworzZwierze(this->getSymbol(), this->x + 1, this->y, this->swiat);
			swiat->dodajOrganizm(nowy);
			komunikat += " rozmnozenie z inna " + this->nazwaOrganizmu(this->getSymbol());
			swiat->dodajKomunikat(komunikat);
			this->setCooldown(5);
			organizm->setCooldown(5);
		}
	}
	else {
		if (organizm->getSila() > this->getSila() && !dynamic_cast<Roslina*>(organizm)) {

			komunikat = komunikat + " ginie przez "; // KOMUNIKATY
			komunikat += organizm->nazwaOrganizmu(this->getSymbol());
			swiat->dodajKomunikat(komunikat);

			swiat->przeniesOrganizm(organizm, this->getX(), this->getY());
			swiat->usunOrganizm(this);
		}
		else {
			if (organizm->getSymbol() == 'Z' || organizm->getSymbol() == 'A' || organizm->getSymbol() == 'g') {
				organizm->kolizja(this);
				return;
			}
			else {
				komunikat = komunikat + " "; // KOMUNIKATY
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
	}
	*/
}

Zwierze::~Zwierze() {}