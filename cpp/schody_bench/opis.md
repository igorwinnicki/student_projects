# Dokumentacja Programu Obliczającego Wymiary Schodów

### Cel Dokumentacji

Celem tej dokumentacji jest przedstawienie implementacji oraz testów programu obliczającego liczbę i wymiary stopni schodów na podstawie całkowitej wysokości i długości schodów. Program ten wykorzystuje wartości minimalnej wysokości oraz długości stopnia, aby zapewnić zgodność z ogólnymi normami budowlanymi.

---

### Opis Funkcji

Plik `functions.cpp` zawiera kluczowe funkcje odpowiedzialne za obliczanie liczby stopni oraz wymiarów pojedynczego stopnia.

#### Funkcja `obliczIloscStopni`

Oblicza maksymalną liczbę stopni, jaką można uzyskać, biorąc pod uwagę wysokość i długość schodów. Funkcja dzieli wysokość oraz długość schodów przez wartości minimalne, a następnie zwraca mniejszą wartość z tych obliczeń, aby zachować spójność z normami budowlanymi.

```cpp
double obliczIloscStopni(double wysokosc, double dlugosc) {
    const double minWysokosc = 15.0;
    const double minDlugosc = 28.0;

    int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc);
    int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc);

    return std::min(iloscStopniWysokosc, iloscStopniDlugosc);
}
