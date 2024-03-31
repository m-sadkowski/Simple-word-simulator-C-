#include"Guarana.h"
#include"Swiat.h"

void Guarana::kolizja(Organizm* organizm) {

	std::string komunikat = "Guarana zjedzona przez  "; // KOMUNIKATY
	komunikat += organizm->nazwaOrganizmu(organizm->getSymbol());
	swiat->dodajKomunikat(komunikat);

	organizm->setSila(organizm->getSila() + 3);
	Roslina::kolizja(organizm);
}
