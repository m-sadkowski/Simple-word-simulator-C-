#include"Guarana.h"
#include"Swiat.h"

void Guarana::kolizja(Organizm* organizm) {
	std::string komunikat = "Guarana zjedzona przez ";
	komunikat += organizm->nazwaOrganizmu(organizm->getSymbol());

	organizm->setSila(organizm->getSila() + 3);
	swiat->przeniesOrganizm(organizm, this->getX(), this->getY());
	swiat->usunOrganizm(this);

	komunikat = komunikat + ", jego sila wzrasta do " + std::to_string(organizm->getSila());
	swiat->dodajKomunikat(komunikat);

	return;
}
