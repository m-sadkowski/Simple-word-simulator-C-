#include<iostream>
#include<windows.h>
#include<string>

#include"Czlowiek.h"
#include"Swiat.h"

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
	std::string komunikat = "Czlowiek na pozycji (" + std::to_string(x) + ", " + std::to_string(y) + ")";
	if (organizm->getSila() > this->sila) {
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

void Czlowiek::aktywujMoc() {
	this->sila = 10;
	this->mocUzyta = true;
	swiat->dodajKomunikat("Czlowiek aktywowal moc");
}

Czlowiek::~Czlowiek() {

}