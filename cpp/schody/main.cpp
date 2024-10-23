#include <iostream>
#include <cmath>

int main() {
    // Zmienne do przechowywania wysokości i długości schodów
    double wysokosc, dlugosc;

    // Pobranie danych od użytkownika
    std::cout << "Podaj wysokość schodów (w cm): ";
    std::cin >> wysokosc;
    std::cout << "Podaj długość schodów (w cm): ";
    std::cin >> dlugosc;

    // Zakresy wysokości i długości stopni
    double minWysokosc = 15.0;
    double maxWysokosc = 17.0;
    double minDlugosc = 28.0;
    double maxDlugosc = 30.0;

    // Obliczenie ilości stopni w oparciu o wysokość
    int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc); // Max ilość stopni
    int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc); // Max ilość stopni

    // Wybór minimalnej ilości stopni
    int iloscStopni = std::min(iloscStopniWysokosc, iloscStopniDlugosc);

    // Wyświetlenie wyniku
    std::cout << "Ilość stopni schodów: " << iloscStopni << std::endl;

    return 0;
}
