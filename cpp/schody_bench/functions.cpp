#include <iostream>
#include <cmath>
#include <algorithm>

// Funkcja wprowadzenia wymiarów schodów przez użytkownika
void wprowadzenieWymiarow(double& wysokosc, double& dlugosc) {
    std::cout << "Podaj wysokość schodów (w cm): ";
    std::cin >> wysokosc;
    
    if (!std::cin) { // Sprawdzamy, czy wprowadzono prawidłowe dane
        std::cerr << "Błąd: Wprowadź liczbę dla wysokości." << std::endl;
        return;
    }

    std::cout << "Podaj długość schodów (w cm): ";
    std::cin >> dlugosc;

    if (!std::cin) { // Sprawdzamy, czy wprowadzono prawidłowe dane
        std::cerr << "Błąd: Wprowadź liczbę dla długości." << std::endl;
        return;
    }
}

// Funkcja obliczająca liczbę stopni na podstawie wysokości i długości schodów
double obliczIloscStopni(double wysokosc, double dlugosc) {
    const double minWysokosc = 15.0;
    const double minDlugosc = 28.0;

    int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc);
    int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc);

    return std::min(iloscStopniWysokosc, iloscStopniDlugosc);
}

// Funkcja obliczająca wymiary pojedynczego stopnia
void obliczWymiaryStopnia(double dlugosc, int iloscStopni, double& dlugoscStopnia, double& wysokoscStopnia) {
    dlugoscStopnia = dlugosc / iloscStopni;
    wysokoscStopnia = wysokosc / iloscStopni;
}
