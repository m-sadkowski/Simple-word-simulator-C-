#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

#include "Cursor.h"
#include "Swiat.h"
#include "Roslina.h"
#include "Czlowiek.h"


int main() {
    srand(time(NULL));
    char strzalka = ' ';
    int m, n;
    std::cout << "Podaj wymiary swiata [m x n]: ";
    std::cin >> m >> n;
    Swiat* swiat = new Swiat(m, n);
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
// OSTATNI PROMPT Z GPT Z ROZMNAZANIEM - > DO ORGANIZMU DODAC FUNKCJE ROZMNAZANIA, NADPISAĆ W ZWIERZECIU I ROŚLINIE

// ZOLW I ANTYLOPA JEST ZHARDCODE'OWANY W ZWIERZE.h I CZLOWIEK.h
// ZROBIC ZE W PRZYPADKU KOLIZJI ODWOLUJE SIE DO KOLIZJI KOLIZYJNEGO Z KOLIZJANTEM I ODWROTNIE -> NIECH KOLIZJANT USUWA SIE DOMYSLNA METODA
// TYLKO FIX ZWIERZETA I DODAC COOLDOWN ROZMNAAZANIA SIE ZWIERZAT

// ZMIANA KOLOROW OPCJONALNIE
// ZAPIS I ODCZYT SWIATA

