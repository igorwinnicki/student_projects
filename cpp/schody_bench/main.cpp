// #include <iostream>
// #include "functions.cpp"

// int main() {
//     double wysokosc = 0.0, dlugosc = 0.0;

//     // Pobranie wymiarów od użytkownika
//     wprowadzenieWymiarow(wysokosc, dlugosc);

//     // Sprawdzenie, czy wprowadzono prawidłowe dane
//     if (wysokosc <= 0 || dlugosc <= 0) {
//         std::cerr << "Nieprawidłowe wymiary, program zakończy działanie." << std::endl;
//         return 1;
//     }

//     // Obliczenie liczby stopni
//     double iloscStopni = obliczIloscStopni(wysokosc, dlugosc);
    
//     // Sprawdzenie, czy obliczenia były możliwe
//     if (iloscStopni > 0) {
//         double dlugoscStopnia = 0.0, wysokoscStopnia = 0.0;

//         // Obliczenie wymiarów stopnia
//         obliczWymiaryStopnia(dlugosc, iloscStopni, dlugoscStopnia, wysokoscStopnia);

//         // Wyświetlenie wyników
//         std::cout << "Liczba stopni: " << iloscStopni << std::endl;
//         std::cout << "Długość pojedynczego stopnia: " << dlugoscStopnia << " cm" << std::endl;
//         std::cout << "Wysokość pojedynczego stopnia: " << wysokoscStopnia << " cm" << std::endl;
//     } else {
//         std::cerr << "Nie można obliczyć schodów z podanych wymiarów." << std::endl;
//     }

//     return 0;
// }
#include <iostream>
#include "functions.cpp"

int main() {
    double wysokosc, dlugosc;
    wprowadzenieWymiarow(wysokosc, dlugosc);

    int iloscStopni = obliczIloscStopni(wysokosc, dlugosc);
    
    if (iloscStopni == -1) {
        std::cerr << "Nie można wygenerować schodów o podanych wymiarach." << std::endl;
        return 1;
    }

    double dlugoscStopnia, wysokoscStopnia;
    obliczWymiaryStopnia(dlugosc, wysokosc, iloscStopni, dlugoscStopnia, wysokoscStopnia);

    std::cout << "Ilość stopni schodów: " << iloscStopni << std::endl;
    std::cout << "Długość pojedynczego stopnia: " << dlugoscStopnia << " cm" << std::endl;
    std::cout << "Wysokość pojedynczego stopnia: " << wysokoscStopnia << " cm" << std::endl;

    return 0;
}


/usr/bin/ld: /tmp/ccd00XwN.o: in function `SchodoweTests_TestWymiaryStopnia_Test::TestBody()':
main_test.cpp:(.text+0x5a5): undefined reference to `obliczWymiaryStopnia(double, int, double&, double&)'
collect2: error: ld returned 1 exit status
---Kompilacja testow ukonczona----
---Uruchamianie programu testujacego---
chmod: cannot access 'main_test': No such file or directory
./kompiluj_test.sh: 15: ./main_test: not found
