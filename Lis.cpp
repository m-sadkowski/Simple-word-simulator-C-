#include<cstdlib>

#include"Lis.h"
#include"Swiat.h"

void Lis::akcja() {
	int newX = this->getX() + (rand() % 3) - 1;
	int newY = this->getY() + (rand() % 3) - 1;

	if (newX <= 0 || newX >= swiat->getSzerokosc() - 1 || newY <= 0 || newY >= swiat->getWysokosc() - 1) {
		return;
	}

	if (swiat->getOrganizm(newX, newY) == nullptr) {
		this->setX(newX);
		this->setY(newY);
	}
	else if (newX != this->getX() || newY != this->getY()) {
		Organizm* organizm = swiat->getOrganizm(newX, newY);
		if (organizm->getSila() > this->getSila())
		{
			swiat->dodajKomunikat("Lis korzysta z dobrego wechu");
			return;
		}
		else {
			this->kolizja(organizm);
		}
	}
}
