#include<cstdlib>

#include"Zolw.h"
#include"Swiat.h"

void Zolw::akcja() {
	if (rand() % 4 == 0) {
		Zwierze::akcja();
	}
}

void Zolw::kolizja(Organizm* organizm) {
	if (organizm->getSymbol() == 'Z') {
		Zwierze::kolizja(organizm);
	}
	else if (organizm->getSila() < 5) {
		swiat->dodajKomunikat("Zolw odparl atak organizmu " + organizm->getSymbol());
	}
	else {
		Zwierze::kolizja(organizm);
	}
}