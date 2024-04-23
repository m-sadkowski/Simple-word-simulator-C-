#include"Cursor.h"
#include"Zwierze.h"
#include"Swiat.h"
#include"Roslina.h"
#include"FabrykaZwierzat.h"

#define COOLDOWN 10

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
	if (organizm->maSwojaKolizje()) { // SPRAWD CZY DANY ORGANIZM MA SPECYFICZN¥ METODÊ KOLIZJI, JEŒLI NIE TO WYKORZYSTAJ T¥
		organizm->kolizja(this);
	} 
	else if (organizm->getSymbol() == this->getSymbol())
	{
		if (organizm->getCooldown() == 0 && this->getCooldown() == 0)
		{
			Zwierze* nowy = FabrykaZwierzat::utworzZwierze(this->getSymbol(), this->x + 1, this->y, this->swiat);
			swiat->dodajOrganizm(nowy);
			std::string komunikat = "rozmnozenie " + this->nazwaOrganizmu(this->getSymbol());
			swiat->dodajKomunikat(komunikat);
			this->setCooldown(COOLDOWN);
			organizm->setCooldown(COOLDOWN);
		}
	}
	else if (dynamic_cast<Roslina*>(organizm))
	{
		std::string komunikat = this->nazwaOrganizmu(this->getSymbol()) + " zjada " + organizm->nazwaOrganizmu(organizm->getSymbol());
		swiat->dodajKomunikat(komunikat);
		swiat->przeniesOrganizm(this, organizm->getX(), organizm->getY());
		swiat->usunOrganizm(organizm);
	}
	else if (organizm->getSila() > this->getSila())
	{
		std::string komunikat = organizm->nazwaOrganizmu(organizm->getSymbol()) + " zabija " + this->nazwaOrganizmu(this->getSymbol());
		swiat->dodajKomunikat(komunikat);
		swiat->przeniesOrganizm(organizm, this->getX(), this->getY());
		swiat->usunOrganizm(this);
	}
	else if (organizm->getSila() <= this->getSila())
	{
		std::string komunikat = this->nazwaOrganizmu(this->getSymbol()) + " zabija " + organizm->nazwaOrganizmu(organizm->getSymbol());
		swiat->dodajKomunikat(komunikat);
		swiat->przeniesOrganizm(this, organizm->getX(), organizm->getY());
		swiat->usunOrganizm(organizm);
	}
}

Zwierze::~Zwierze() {}