#include"Swiat.h"
#include<iostream>

Swiat::Swiat(int m, int n) {
	this->m = m;
	this->n = n;
	plansza = new char*[m];
	for (int i = 0; i < m; i++) {
		plansza[i] = new char[n];
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
				plansza[i][j] = '#';
			}
			else {
				plansza[i][j] = '.';
			}
		}
	}
}

void Swiat::rysujSwiat() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << plansza[i][j];
		}
		std::cout << std::endl;
	}
}

void Swiat::wykonajTure(char strzalka) {

}