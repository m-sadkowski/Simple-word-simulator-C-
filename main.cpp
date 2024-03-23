#include <iostream>
#include <conio.h>
#include "Swiat.h"

int main() {
    char strzalka = ' ';
    int m, n;
    std::cout << "Podaj wymiary swiata [m x n]: ";
    std::cin >> m >> n;
    Swiat* swiat = new Swiat(m, n);
    while (!_kbhit()) {
        system("cls");
        swiat->rysujSwiat();
		swiat->wykonajTure(strzalka);
        strzalka = _getch();
        if (strzalka == 'q') {
            break;
        }
	}
    delete swiat;
}