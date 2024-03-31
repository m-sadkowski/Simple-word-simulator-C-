#include"Mlecz.h"
#include"Swiat.h"

void Mlecz::akcja() {
	
	for (int i = 0; i < 3; i++)
	{
		int prawdopodobienstwo = rand() % 100;
		if (prawdopodobienstwo > 95)
		{
			int newX = this->getX() + (rand() % 2) - 1;
			int newY = this->getY() + (rand() % 2) - 1;

			if (newX <= 0 || newX >= swiat->getSzerokosc() - 1 || newY <= 0 || newY >= swiat->getWysokosc() - 1 || swiat->getOrganizm(newX, newY) != nullptr) {
				continue;
			}
			else
			{
				swiat->dodajOrganizm(new Roslina(this->sila, this->inicjatywa, this->symbol, newX, newY, this->swiat));
				break;
			}
		}
	}
}
