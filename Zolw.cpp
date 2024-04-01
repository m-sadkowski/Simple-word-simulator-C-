#include"Zolw.h"
#include"Swiat.h"
#include"Roslina.h"

void Zolw::akcja() {
	if (rand() % 4 == 0) {
		Zwierze::akcja();
	}
}

void Zolw::kolizja(Organizm* organizm) {
	if (organizm->getSila() < 5 && !dynamic_cast<Roslina*>(organizm))
	{
		std::string komunikat = "Zolw blokuje atak " + organizm->nazwaOrganizmu(organizm->getSymbol());
		swiat->dodajKomunikat(komunikat);
	}
	else
	{
		this->Zwierze::kolizja(organizm);
	}
	return;
}