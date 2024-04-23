#include"Roslina.h"
#include"Swiat.h"
#include"Cursor.h"
#include"FabrykaRoslin.h"

using namespace std;

void Roslina::akcja() {
	int prawdopodobienstwo = rand() % 100;
	if (prawdopodobienstwo > 95)
	{
		int newX = this->getX() + (rand() % 3) - 1;
		int newY = this->getY() + (rand() % 3) - 1;

		if (newX <= 0 || newX >= swiat->getSzerokosc() - 1 || newY <= 0 || newY >= swiat->getWysokosc() - 1 || swiat->getOrganizm(newX, newY) != nullptr) {
			return;
		}
		Roslina* nowa = FabrykaRoslin::utworzRosline(this->getSymbol(), newX, newY, this->swiat);
		swiat->dodajOrganizm(nowa);

		std::string komunikat = "rozprzestrzenia sie "; // KOMUNIKATY
		komunikat += this->nazwaOrganizmu(this->getSymbol());
		swiat->dodajKomunikat(komunikat);
	}
}

void Roslina::kolizja(Organizm* organizm) {
	return;
}

Roslina::~Roslina() {}