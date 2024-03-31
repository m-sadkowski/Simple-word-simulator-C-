#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

#include "Cursor.h"
#include "Swiat.h"
#include "Roslina.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Zolw.h"
#include "Lis.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"

int main() {
    srand(time(NULL));
    char strzalka = ' ';
    int m, n;
    std::cout << "Podaj wymiary swiata [m x n]: ";
    std::cin >> m >> n;
    Swiat* swiat = new Swiat(m, n);
    swiat->dodajOrganizm(new Owca(3, 4, swiat));
    swiat->dodajOrganizm(new Wilk(5, 7, swiat));
    swiat->dodajOrganizm(new Zolw(9, 8, swiat));
    swiat->dodajOrganizm(new Lis(5, 2, swiat));
    swiat->dodajOrganizm(new Antylopa(2, 3, swiat));
    swiat->dodajOrganizm(new Czlowiek(m/2, n/2, swiat));
    swiat->dodajOrganizm(new Trawa(1, 1, swiat));
    swiat->dodajOrganizm(new Mlecz(15, 14, swiat));
    swiat->rysujSwiat();
    while (1) {
        strzalka = _getch();
        if (strzalka == 'q') {
            break;
        }
        swiat->wykonajTure(strzalka);
        swiat->rysujSwiat();
	}
    delete swiat;
    return 0;
}

// NIE WIADOMO JAK JEST Z ROZMNAZANIEM ZWIERZAT, CZY WILK JEST WILKIEM CZY TYLKO ZWIERZEM Z ARGUMENTAMI WILKA
// ZOLW I ANTYLOPA JEST ZHARDCODE'OWANY W ZWIERZE.h I CZLOWIEK.h
// DO DODANIA GUARANA I WILCZE JAGODY
// GENEROWANIE ORGANIZMOW NA SWIAT
// ZMIANA KOLOROW OPCJONALNIE
// ZAPIS I ODCZYT SWIATA

// OSTATNI PROMPT Z GPT Z ROZMNAZANIEM - > DO ORGANIZMU DODAC FUNKCJE ROZMNAZANIA, NADPISAĆ W ZWIERZECIU I ROŚLINIE