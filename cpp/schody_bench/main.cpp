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
