#pragma once
#include "Zwierze.h"
#include "Wilk.h"
#include "Zolw.h"
#include "Lis.h"
#include "Antylopa.h"
#include "Owca.h"

class FabrykaZwierzat {
public:
    static Zwierze* utworzZwierze(char symbol, int x, int y, Swiat* swiat) {
        switch (symbol) {
        case 'W':
            return new Wilk(x, y, swiat);
        case 'Z':
            return new Zolw(x, y, swiat);
        case 'L':
			return new Lis(x, y, swiat);
        case 'A':
            return new Antylopa(x, y, swiat);
        case 'O':
            return new Owca(x, y, swiat);
        default:
            return nullptr;
        }
    }
};