#include <iostream>
#include <cmath>

int main() {
    double wysokosc, dlugosc;

    std::cout << "Podaj wysokość schodów (w cm): ";
    std::cin >> wysokosc;
    std::cout << "Podaj długość schodów (w cm): ";
    std::cin >> dlugosc;

    double minWysokosc = 15.0;
    double maxWysokosc = 17.0;
    double minDlugosc = 28.0;
    double maxDlugosc = 30.0;
    
    int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc);
    int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc);

    int iloscStopni = std::min(iloscStopniWysokosc, iloscStopniDlugosc);

    double dlugoscStopnia = dlugosc / iloscStopni;
    double szerokoscStopnia = minWysokosc;

    std::cout << "Ilość stopni schodów: " << iloscStopni << std::endl;
    std::cout << "Długość pojedynczego stopnia: " << dlugoscStopnia << " cm" << std::endl;
    std::cout << "Szerokość pojedynczego stopnia: " << szerokoscStopnia << " cm" << std::endl;

    return 0;
}
