#include <iostream>
#include <cmath>
#include <algorithm>

double obliczIloscStopni(double wysokosc, double dlugosc) {
    const double minWysokosc = 15.0;
    const double minDlugosc = 28.0;

    int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc);
    int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc);

    return std::min(iloscStopniWysokosc, iloscStopniDlugosc);
}

void obliczWymiaryStopnia(double dlugosc, int iloscStopni, double& dlugoscStopnia, double& szerokoscStopnia) {
    dlugoscStopnia = dlugosc / iloscStopni;
    szerokoscStopnia = 15.0; // Szerokość stopnia ustalamy na stałą wartość
}

void wprowadzenieWymiarow(double& wysokosc, double& dlugosc) {
    // Funkcja pozostaje bez zmian, ale można zamockować jej działanie w testach
    std::cout << "Podaj wysokość schodów (w cm): ";
    std::cin >> wysokosc;
    std::cout << "Podaj długość schodów (w cm): ";
    std::cin >> dlugosc;
}
