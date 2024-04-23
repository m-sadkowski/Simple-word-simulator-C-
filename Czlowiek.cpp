#include"Czlowiek.h"
#include"Swiat.h"
#include"Roslina.h"

#define COOLDOWN 20
#define MOC 5

void Czlowiek::akcja(char c) {
	// OBSLUGA MOCY
	if (cooldown > 0)
	{
		cooldown--;
	}
	if (mocUzyta) {
		czasMocy++;
	}
	if (czasMocy == MOC + 1)
	{
		mocUzyta = false;
		czasMocy = 0;
		cooldown = COOLDOWN;
	}
	if (this->sila > stalaSila && mocUzyta)
	{
		this->sila--;
		swiat->dodajKomunikat("Sila czlowieka wynosi " + std::to_string(this->sila));
	}
	// RUCH
	int newX = this->x;
	int newY = this->y;
	if (c == ARROW_UP) {
		if (this->y > 1) {
			newY--;
		}
	}
	else if (c == ARROW_DOWN) {
		if (this->y < swiat->getWysokosc() - 2) {
			newY++;
		}
	}
	else if (c == ARROW_LEFT) {
		if (this->x > 1) {
			newX--;
		}
	}
	else if (c == ARROW_RIGHT) {
		if (this->x < swiat->getSzerokosc() - 2) {
			newX++;
		}
	}
	else if (c == 'm') {
		if (!mocUzyta && !cooldown) {
			aktywujMoc();
		}
	}

	// KOLIZJA PO RUCHU
	if (newX != this->x || newY != this->y) {
		if (swiat->getOrganizm(newX, newY) != nullptr)
		{
			this->Zwierze::kolizja(swiat->getOrganizm(newX, newY));
			
		}
		else
		{
			swiat->przeniesOrganizm(this, newX, newY);
		}
	}
}

void Czlowiek::aktywujMoc() {
	this->sila += MOC;
	this->mocUzyta = true;
	swiat->dodajKomunikat("Czlowiek wypil eliksir");
}

Czlowiek::~Czlowiek() {}