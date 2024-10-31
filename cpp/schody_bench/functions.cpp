#include "functions.h"
#include <iostream>
#include <cmath>
#include <algorithm>

double obliczIloscStopni(double wysokosc, double dlugosc) {
    const double minWysokosc = 15.0;
    const double minDlugosc = 28.0;

    // Sprawdzanie minimalnych wymagań długości i wysokości
    if (wysokosc < minWysokosc || dlugosc < minDlugosc) {
        std::cerr << "Błąd: Wymiary schodów są zbyt małe, aby obliczyć stopnie." << std::endl;
        return 0;
    }

    int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc);
    int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc);

    return std::min(iloscStopniWysokosc, iloscStopniDlugosc);
}

void obliczWymiaryStopnia(double dlugosc, int iloscStopni, double& dlugoscStopnia, double& szerokoscStopnia) {
    if (iloscStopni <= 0) {
        std::cerr << "Błąd: Liczba stopni musi być większa od zera, aby obliczyć wymiary." << std::endl;
        dlugoscStopnia = 0;
        szerokoscStopnia = 0;
        return;
    }

    dlugoscStopnia = dlugosc / iloscStopni;
    szerokoscStopnia = 15.0; // Szerokość stopnia ustalamy na stałą wartość
}

void wprowadzenieWymiarow(double& wysokosc, double& dlugosc) {
    std::cout << "Podaj wysokość schodów (w cm): ";
    std::cin >> wysokosc;
    std::cout << "Podaj długość schodów (w cm): ";
    std::cin >> dlugosc;

    // Sprawdzanie, czy wprowadzone wymiary są większe od minimalnych wymaganych wartości
    if (wysokosc < 15.0) {
        std::cerr << "Ostrzeżenie: Wysokość schodów jest mniejsza od minimalnej wartości 15 cm." << std::endl;
    }
    if (dlugosc < 28.0) {
        std::cerr << "Ostrzeżenie: Długość schodów jest mniejsza od minimalnej wartości 28 cm." << std::endl;
    }
}

