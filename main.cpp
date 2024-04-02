#include <ctime>
#include <conio.h>

#include "Cursor.h"
#include "Swiat.h"


int main() {
    Swiat* swiat = new Swiat(0, 0);
    srand(static_cast<unsigned int>(time(NULL)));
    char strzalka = ' ';
    std::cout << "Wcisnij w aby wczytac zapis gry." << std::endl;
    std::cout << "Wcisnij n aby rozpoczac nowa gre." << std::endl;
    while (strzalka = _getch())
    {
        system("cls");
        std::cout << "Wcisnij w aby wczytac zapis gry." << std::endl;
        std::cout << "Wcisnij n aby rozpoczac nowa gre." << std::endl;
        if (strzalka == 'w')
        {
            swiat->wczytajSwiat();
            swiat->rysujSwiat();
            break;
        }
        else if (strzalka == 'n')
        {
            int m, n;
            std::cout << "Podaj wymiary swiata [m x n]: ";
            std::cin >> m >> n;
            swiat = new Swiat(m, n);
            swiat->generujSwiat();
            swiat->rysujSwiat();
            break;
        }
    }
    while (1) {
        strzalka = _getch();
        if (strzalka == 'q') {
            break;
        }
        else if (strzalka == 'z')
        {
            swiat->zapiszSwiat();
            continue;
        }
        swiat->wykonajTure(strzalka);
        swiat->rysujSwiat();
    }
    delete swiat;
    return 0;

    // moc przy czlowieku zapis odczyt
}


