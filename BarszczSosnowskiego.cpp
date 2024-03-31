#include"BarszczSosnowskiego.h"
#include"Swiat.h"

void BarszczSosnowskiego::kolizja(Organizm* organizm) {
	if (organizm->getSymbol() != 'Y') {
		swiat->usunOrganizm(organizm);
	}	
	else {
		swiat->usunOrganizm(this);
	}
}

void BarszczSosnowskiego::akcja() {
	if (swiat->getOrganizm(x, y + 1) != nullptr) {

		std::string komunikat = "Barszcz Sosnowskiego zabija "; // KOMUNIKATY
		komunikat += swiat->getOrganizm(x, y + 1)->nazwaOrganizmu(swiat->getOrganizm(x, y + 1)->getSymbol());
		swiat->dodajKomunikat(komunikat);

		swiat->usunOrganizm(swiat->getOrganizm(x, y + 1));
	}
	if (swiat->getOrganizm(x, y - 1) != nullptr) {

		std::string komunikat = "Barszcz Sosnowskiego zabija "; // KOMUNIKATY
		komunikat += swiat->getOrganizm(x, y - 1)->nazwaOrganizmu(swiat->getOrganizm(x, y - 1)->getSymbol());
		swiat->dodajKomunikat(komunikat);

		swiat->usunOrganizm(swiat->getOrganizm(x, y - 1));
	}
	if (swiat->getOrganizm(x + 1, y) != nullptr) {

		std::string komunikat = "Barszcz Sosnowskiego zabija "; // KOMUNIKATY
		komunikat += swiat->getOrganizm(x + 1, y)->nazwaOrganizmu(swiat->getOrganizm(x + 1, y)->getSymbol());
		swiat->dodajKomunikat(komunikat);
		
		swiat->usunOrganizm(swiat->getOrganizm(x + 1, y));
	}
	if (swiat->getOrganizm(x - 1, y) != nullptr) {

		std::string komunikat = "Barszcz Sosnowskiego zabija "; // KOMUNIKATY
		komunikat += swiat->getOrganizm(x - 1, y)->nazwaOrganizmu(swiat->getOrganizm(x - 1, y)->getSymbol());
		swiat->dodajKomunikat(komunikat);
		
		swiat->usunOrganizm(swiat->getOrganizm(x - 1, y));

	}
}
