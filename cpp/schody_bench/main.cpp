#include <iostream>
#include "functions.cpp"

int main() {
    double wysokosc = 0.0, dlugosc = 0.0;

    // Pobranie wymiarów od użytkownika
    wprowadzenieWymiarow(wysokosc, dlugosc);

    // Sprawdzenie, czy wprowadzono prawidłowe dane
    if (wysokosc <= 0 || dlugosc <= 0) {
        std::cerr << "Nieprawidłowe wymiary, program zakończy działanie." << std::endl;
        return 1;
    }

    // Obliczenie liczby stopni
    double iloscStopni = obliczIloscStopni(wysokosc, dlugosc);
    
    // Sprawdzenie, czy obliczenia były możliwe
    if (iloscStopni > 0) {
        double dlugoscStopnia = 0.0, wysokoscStopnia = 0.0;

        // Obliczenie wymiarów stopnia
        obliczWymiaryStopnia(dlugosc, iloscStopni, dlugoscStopnia, wysokoscStopnia);

        // Wyświetlenie wyników
        std::cout << "Liczba stopni: " << iloscStopni << std::endl;
        std::cout << "Długość pojedynczego stopnia: " << dlugoscStopnia << " cm" << std::endl;
        std::cout << "Szerokość pojedynczego stopnia: " << wysokoscStopnia << " cm" << std::endl;
    } else {
        std::cerr << "Nie można obliczyć schodów z podanych wymiarów." << std::endl;
    }

    return 0;
}

