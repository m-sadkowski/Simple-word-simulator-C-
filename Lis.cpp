#include"Lis.h"
#include"Swiat.h"

void Lis::akcja() {
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
		Lis::akcja();
		return;
	}

	if (swiat->getOrganizm(newX, newY) == nullptr) {
		swiat->przeniesOrganizm(this, newX, newY);
	}
	else if (newX != this->getX() || newY != this->getY()) {
		Organizm* organizm = swiat->getOrganizm(newX, newY);
		if (organizm->getSila() > this->getSila()) {
			std::string komunikat = "Lis korzysta z dobrego wechu i omija " + organizm->nazwaOrganizmu(organizm->getSymbol());
			swiat->dodajKomunikat(komunikat);
		}
		else {
			this->Zwierze::kolizja(organizm);
		}
	}
}
