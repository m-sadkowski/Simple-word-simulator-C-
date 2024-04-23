#include"WilczeJagody.h"
#include"Swiat.h"

void WilczeJagody::kolizja(Organizm* organizm) {
	std::string komunikat = "Wilcze Jagody zabijaja " + organizm->nazwaOrganizmu(organizm->getSymbol());
	swiat->usunOrganizm(organizm);
	swiat->dodajKomunikat(komunikat);
	swiat->usunOrganizm(this);
	return;
}