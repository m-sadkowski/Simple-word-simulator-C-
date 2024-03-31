#include"WilczeJagody.h"
#include"Swiat.h"

void WilczeJagody::kolizja(Organizm* organizm) {
	swiat->dodajKomunikat("Wilcze Jagody zatruwaja " + organizm->getSymbol());
	swiat->usunOrganizm(organizm);
}