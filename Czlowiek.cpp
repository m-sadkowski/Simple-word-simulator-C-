#include"Czlowiek.h"
#include"Swiat.h"
#include"Roslina.h"

void Czlowiek::akcja(char c) {
	
	//swiat->dodajKomunikat("Sila czlowieka wynosi" + std::to_string(this->sila));
	// OBSLUGA MOCY
	if (czasMocy == 5)
	{
		this->sila = stalaSila;
		mocUzyta = false;
		czasMocy = 0;
		cooldown = 5;
	}
	if (this->sila > stalaSila)
	{
		this->sila--;
	}

	// RUCH
	int newX = this->x;
	int newY = this->y;
	if (c == 'w') {
		if (this->y > 1) {
			newY--;
		}
	}
	else if (c == 's') {
		if (this->y < swiat->getWysokosc() - 2) {
			newY++;
		}
	}
	else if (c == 'a') {
		if (this->x > 1) {
			newX--;
		}
	}
	else if (c == 'd') {
		if (this->x < swiat->getSzerokosc() - 2) {
			newX++;
		}
	}
	else if (c == 'm') {
		if (!mocUzyta && !cooldown) {
			aktywujMoc();
			czasMocy++;
		}
	}

	// KOLIZJA PO RUCHU
	if (swiat->getOrganizm(newX, newY) != nullptr && (newX != x || newY != y))
	{
		kolizja(swiat->getOrganizm(newX, newY));
		if (this != nullptr && swiat->getOrganizm(newX, newY) == nullptr)
		{
			swiat->przeniesOrganizm(this, newX, newY);
		}
	}
	else
	{
		swiat->przeniesOrganizm(this, newX, newY);
	}
	
}

void Czlowiek::kolizja(Organizm* organizm) {
	/*
	if (organizm->getSila() > this->sila) {
		std::string komunikat = "Czlowiek ginie przez "; // KOMUNIKATY
		komunikat += organizm->nazwaOrganizmu(organizm->getSymbol());
		swiat->dodajKomunikat(komunikat);

		swiat->przeniesOrganizm(organizm, this->getX(), this->getY());
		swiat->usunOrganizm(this);
	}
	else {
		if (organizm->getSymbol() == 'Z' || organizm->getSymbol() == 'A' || organizm->getSymbol() == 'g') {
			organizm->kolizja(this);
		}
		else {
			std::string komunikat = "Czlowiek "; // KOMUNIKATY
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
	}*/
}

void Czlowiek::aktywujMoc() {
	this->sila = 10;
	this->mocUzyta = true;
	swiat->dodajKomunikat("Czlowiek aktywowal moc");
}

Czlowiek::~Czlowiek() {

}