# Dokumentacja Schodów

### Cel Dokumentacji

Celem tej dokumentacji jest przedstawienie implementacji oraz testów funkcji służących do obliczania liczby oraz wymiarów stopni schodów. Program przyjmuje wysokość i długość schodów, a następnie oblicza liczbę stopni oraz ich wymiary.

### Opis Funkcji

#### Funkcja `obliczIloscStopni`

Funkcja oblicza maksymalną liczbę stopni schodów na podstawie ich całkowitej wysokości i długości.

```cpp
double obliczIloscStopni(double wysokosc, double dlugosc) {
    const double minWysokosc = 15.0;
    const double minDlugosc = 28.0;

    int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc);
    int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc);

    return std::min(iloscStopniWysokosc, iloscStopniDlugosc);
}
```

**Parametry:**
- `wysokosc` - wysokość całkowita schodów (w cm).
- `dlugosc` - długość całkowita schodów (w cm).

**Zwraca:** Mniejszą wartość z liczby stopni obliczonych na podstawie wysokości i długości schodów.

---

#### Funkcja `obliczWymiaryStopnia`

Funkcja oblicza długość pojedynczego stopnia oraz ustawia jego szerokość na wartość stałą.

//kod

**Parametry:**
- `dlugosc` - całkowita długość schodów (w cm).
- `iloscStopni` - liczba stopni.
- `dlugoscStopnia` - referencja do zmiennej przechowującej długość pojedynczego stopnia.
- `szerokoscStopnia` - referencja do zmiennej przechowującej szerokość pojedynczego stopnia.

---

#### Funkcja `wprowadzenieWymiarow`

Funkcja pobiera od użytkownika wartości wysokości i długości schodów.

//kod

**Parametry:**
- `wysokosc` - referencja do zmiennej, która przechowa wprowadzoną wartość wysokości schodów.
- `dlugosc` - referencja do zmiennej, która przechowa wprowadzoną wartość długości schodów.

---

### Testy

Testy weryfikują poprawność działania funkcji z pliku `functions.cpp` przy użyciu frameworka Google Test (`GTest`). 

#### 1. Test dla `obliczIloscStopni`

Pierwszy test sprawdza, czy funkcja zwraca poprawną liczbę stopni dla różnych danych wejściowych.

//kod

#### 2. Test dla `obliczWymiaryStopnia`

Drugi test weryfikuje, czy funkcja oblicza długość i szerokość stopnia prawidłowo.

//kod

#### 3. Test Automatyczny

Test automatyczny może weryfikować działanie funkcji `obliczIloscStopni` dla szerszego zakresu danych.

//kod

### Podsumowanie

Program do obliczania wymiarów schodów przeszedł wszystkie testy, co potwierdza jego poprawność i niezawodność. Testy obejmują wszystkie istotne przypadki, co zwiększa pewność w jego działaniu.

### Przykład Wykonanego Kodu

Kod został przetestowany i działa zgodnie z oczekiwaniami, zwracając poprawne wyniki dla wszystkich testowanych przypadków.
