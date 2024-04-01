#include"Zolw.h"
#include"Swiat.h"
#include"Roslina.h"

void Zolw::akcja() {
	if (rand() % 4 == 0) {
		Zwierze::akcja();
	}
}

void Zolw::kolizja(Organizm* organizm) {
	/*
	if (organizm->getSymbol() == this->getSymbol()) {
		Zwierze::kolizja(organizm);
		return;
	}
	else if (organizm->getSila() < 5 && !dynamic_cast<Roslina*>(organizm)) {

		std::string komunikat = "Zolw odparl atak "; // KOMUNIKATY
		komunikat += organizm->nazwaOrganizmu(organizm->getSymbol());
		swiat->dodajKomunikat(komunikat);

	}
	else {
		if (organizm->getSila() > this->getSila())
		{
			std::string komunikat = "Zolw ginie przez "; // KOMUNIKATY
			komunikat += organizm->nazwaOrganizmu(organizm->getSymbol());
			swiat->dodajKomunikat(komunikat);

			swiat->przeniesOrganizm(organizm, this->getX(), this->getY());
			swiat->usunOrganizm(this);
		}
		else {
			std::string komunikat = "Zolw "; // KOMUNIKATY
			Roslina* roslina = dynamic_cast<Roslina*>(organizm);
			if (roslina) {
				komunikat += "zjada ";
			}
			else {
				komunikat += "zabija ";
			}
			komunikat += organizm->nazwaOrganizmu(organizm->getSymbol());
			swiat->dodajKomunikat(komunikat);

			swiat->przeniesOrganizm(this, organizm->getX(), organizm->getY());
			swiat->usunOrganizm(organizm);
		}
	}
	*/
}