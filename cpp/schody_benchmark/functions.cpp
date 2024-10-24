#include <iostream>
#include <cmath>

// Funkcja do obliczenia liczby stopni
int obliczIloscStopni(double wysokosc, double dlugosc) {
    const double minWysokosc = 15.0;
    const double minDlugosc = 28.0;

    int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc);
    int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc);

    return std::min(iloscStopniWysokosc, iloscStopniDlugosc);
}

// Funkcja do obliczenia wymiarów stopnia
void obliczWymiaryStopnia(double dlugosc, int iloscStopni, double& dlugoscStopnia, double& szerokoscStopnia) {
    dlugoscStopnia = dlugosc / iloscStopni;
    szerokoscStopnia = 15.0; // Szerokość stopnia ustalamy na stałą wartość
}
