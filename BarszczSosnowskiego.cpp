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
	bool atak = false;
	if (swiat->getOrganizm(x, y + 1) != nullptr) {
		atak = true;
		swiat->usunOrganizm(swiat->getOrganizm(x, y + 1));
	}
	if (swiat->getOrganizm(x, y - 1) != nullptr) {
		atak = true;
		swiat->usunOrganizm(swiat->getOrganizm(x, y - 1));
	}
	if (swiat->getOrganizm(x + 1, y) != nullptr) {
		atak = true;
		swiat->usunOrganizm(swiat->getOrganizm(x + 1, y));
	}
	if (swiat->getOrganizm(x - 1, y) != nullptr) {
		atak = true;
		swiat->usunOrganizm(swiat->getOrganizm(x - 1, y));

	}
	if(atak) swiat->dodajKomunikat("Barszcz Sosnowskiego atakuje ");
}
