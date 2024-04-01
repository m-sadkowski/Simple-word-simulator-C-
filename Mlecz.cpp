#include"Mlecz.h"
#include"Swiat.h"

void Mlecz::akcja() {
	for (int i = 0; i < 3; i++)
	{
		size_t iloscOrganizmow = swiat->getIloscOrganizmow();
		Roslina::akcja();
		if (iloscOrganizmow > swiat->getIloscOrganizmow())
		{
			break;
		}
	}
}
