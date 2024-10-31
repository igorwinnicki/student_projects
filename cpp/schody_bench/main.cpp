#include <iostream>
#include "functions.cpp"

int main() {
    double wysokosc, dlugosc;

    // Pobranie wymiarów od użytkownika
    wprowadzenieWymiarow(wysokosc, dlugosc);

    // Obliczenie liczby stopni
    double iloscStopni = obliczIloscStopni(wysokosc, dlugosc);
    
    // Sprawdzenie, czy obliczenia były możliwe
    if (iloscStopni > 0) {
        double dlugoscStopnia, szerokoscStopnia;

        // Obliczenie wymiarów stopnia
        obliczWymiaryStopnia(dlugosc, iloscStopni, dlugoscStopnia, szerokoscStopnia);

        // Wyświetlenie wyników
        std::cout << "Liczba stopni: " << iloscStopni << std::endl;
        std::cout << "Długość pojedynczego stopnia: " << dlugoscStopnia << " cm" << std::endl;
        std::cout << "Szerokość pojedynczego stopnia: " << szerokoscStopnia << " cm" << std::endl;
    } else {
        std::cerr << "Nie można obliczyć schodów z podanych wymiarów." << std::endl;
    }

    return 0;
}
