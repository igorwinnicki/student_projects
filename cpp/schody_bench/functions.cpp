// #include <iostream>
// #include <cmath>
// #include <algorithm>

// // Funkcja wprowadzenia wymiarów schodów przez użytkownika
// void wprowadzenieWymiarow(double& wysokosc, double& dlugosc) {
//     std::cout << "Podaj wysokość schodów (w cm): ";
//     std::cin >> wysokosc;
    
//     if (!std::cin) { // Sprawdzamy, czy wprowadzono prawidłowe dane
//         std::cerr << "Błąd: Wprowadź liczbę dla wysokości." << std::endl;
//         return;
//     }

//     std::cout << "Podaj długość schodów (w cm): ";
//     std::cin >> dlugosc;

//     if (!std::cin) { // Sprawdzamy, czy wprowadzono prawidłowe dane
//         std::cerr << "Błąd: Wprowadź liczbę dla długości." << std::endl;
//         return;
//     }
// }

// // Funkcja obliczająca liczbę stopni na podstawie wysokości i długości schodów
// double obliczIloscStopni(double wysokosc, double dlugosc) {
//     const double minWysokosc = 15.0;
//     const double minDlugosc = 28.0;

//     int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc);
//     int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc);

//     return std::min(iloscStopniWysokosc, iloscStopniDlugosc);
// }

// // Funkcja obliczająca wymiary pojedynczego stopnia
// void obliczWymiaryStopnia(double dlugosc, double& wysokosc, int iloscStopni, double& dlugoscStopnia, double& wysokoscStopnia) {
//     dlugoscStopnia = dlugosc / iloscStopni;
//     wysokoscStopnia = wysokosc / iloscStopni;
// }

#include <iostream>
#include <cmath>
#include <algorithm>

// Funkcja obliczająca liczbę stopni schodów z uwzględnieniem minimalnych wymagań na wysokość i długość.
double obliczIloscStopni(double wysokosc, double dlugosc) {
    const double minWysokosc = 15.0;  // Minimalna wysokość stopnia
    const double minDlugosc = 28.0;   // Minimalna długość stopnia
    const double maxWysokosc = 17.0;  // Maksymalna wysokość stopnia
    const double maxDlugosc = 30.0;   // Maksymalna długość stopnia

    int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc);
    int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc);

    int iloscStopni = std::min(iloscStopniWysokosc, iloscStopniDlugosc);

    // Walidacja: sprawdzenie, czy wymiar stopni mieści się w wymaganych limitach.
    if (wysokosc / iloscStopni > maxWysokosc || dlugosc / iloscStopni > maxDlugosc) {
        std::cerr << "Błąd: Schody nie mogą być obliczone w wymaganych wymiarach." << std::endl;
        return -1;  // Wartość -1 sygnalizuje błąd
    }

    return iloscStopni;
}

// Funkcja obliczająca wymiary pojedynczego stopnia z uwzględnieniem wysokości i długości.
void obliczWymiaryStopnia(double dlugosc, double wysokosc, int iloscStopni, double& dlugoscStopnia, double& wysokoscStopnia) {
    dlugoscStopnia = dlugosc / iloscStopni;    // Obliczenie długości pojedynczego stopnia
    wysokoscStopnia = wysokosc / iloscStopni;  // Obliczenie wysokości pojedynczego stopnia
}

// Funkcja pobierająca wymiary schodów od użytkownika.
void wprowadzenieWymiarow(double& wysokosc, double& dlugosc) {
    std::cout << "Podaj wysokość schodów (w cm): ";
    std::cin >> wysokosc;
    std::cout << "Podaj długość schodów (w cm): ";
    std::cin >> dlugosc;
}
