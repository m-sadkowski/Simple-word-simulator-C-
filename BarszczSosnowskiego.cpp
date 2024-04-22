#include"BarszczSosnowskiego.h"
#include"Swiat.h"

void BarszczSosnowskiego::kolizja(Organizm* organizm) {
	std::string komunikat = "Barszcz Sosnowskiego zabija " + organizm->nazwaOrganizmu(organizm->getSymbol());
	swiat->usunOrganizm(organizm);
	return;
}

void BarszczSosnowskiego::akcja() {
	const int X[4] = { 0, 0, 1, -1 };
	const int Y[4] = { 1, -1, 0, 0 };
	for (int i = 0; i < 4; i++) {
		if (swiat->getOrganizm(x + X[i], y + Y[i]) != nullptr && !dynamic_cast<Roslina*>(swiat->getOrganizm(x + X[i], y + Y[i]))) {

			std::string komunikat = "Barszcz Sosnowskiego zabija ";
			komunikat += swiat->getOrganizm(x + X[i], y + Y[i])->nazwaOrganizmu(swiat->getOrganizm(x + X[i], y + Y[i])->getSymbol());
			swiat->dodajKomunikat(komunikat);

			swiat->usunOrganizm(swiat->getOrganizm(x + X[i], y + Y[i]));
		}
	}
}
