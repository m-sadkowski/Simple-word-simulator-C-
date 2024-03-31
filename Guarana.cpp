#include"Guarana.h"
#include"Swiat.h"

void Guarana::kolizja(Organizm* organizm) {
	swiat->dodajKomunikat("Guarana zostala zjedzona przez " + organizm->getSymbol());
	organizm->setSila(organizm->getSila() + 3);
	Roslina::kolizja(organizm);
}
