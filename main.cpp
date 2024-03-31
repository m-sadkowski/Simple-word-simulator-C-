#include <ctime>
#include <conio.h>

#include "Cursor.h"
#include "Swiat.h"


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

// ZAPIS I ODCZYT SWIATA

