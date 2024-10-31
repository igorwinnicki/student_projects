# Dokumentacja Schodowego Kalkulatora

### Cel Dokumentacji

Celem tej dokumentacji jest przedstawienie implementacji oraz testów programu do obliczania liczby stopni schodów na podstawie wprowadzonych wymiarów (wysokości i długości schodów) oraz wyznaczanie długości i szerokości pojedynczego stopnia. Dodatkowo, przedstawiono aktualizację funkcji o walidację wartości wejściowych, aby zapobiec błędom wynikającym z niepoprawnych danych wejściowych.

### Opis Funkcji

#### Funkcja `obliczIloscStopni`

Funkcja `obliczIloscStopni` oblicza maksymalną liczbę stopni schodów, jakie można uzyskać na podstawie minimalnych wymagań dla ich wysokości i długości. Dodano również walidację, która wyświetla błąd i zwraca `0`, jeśli wartości wejściowe są zbyt małe, aby obliczyć poprawną liczbę stopni.

```cpp
double obliczIloscStopni(double wysokosc, double dlugosc) {
    const double minWysokosc = 15.0;
    const double minDlugosc = 28.0;

    if (wysokosc < minWysokosc || dlugosc < minDlugosc) {
        std::cerr << "Wymiary schodów są za małe, aby obliczyć liczbę stopni.\n";
        return 0;
    }

    int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc);
    int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc);

    return std::min(iloscStopniWysokosc, iloscStopniDlugosc);
}
```

#### Funkcja `obliczWymiaryStopnia`

Funkcja `obliczWymiaryStopnia` oblicza długość i szerokość pojedynczego stopnia na podstawie długości schodów oraz liczby stopni. Jeśli liczba stopni jest niepoprawna (mniejsza lub równa 0), funkcja wypisuje komunikat o błędzie i ustawia wartości długości i szerokości stopnia na `0`.

```cpp
void obliczWymiaryStopnia(double dlugosc, int iloscStopni, double& dlugoscStopnia, double& szerokoscStopnia) {
    if (iloscStopni <= 0) {
        std::cerr << "Błędna liczba stopni. Nie można obliczyć wymiarów stopnia.\n";
        dlugoscStopnia = 0;
        szerokoscStopnia = 0;
        return;
    }
    dlugoscStopnia = dlugosc / iloscStopni;
    szerokoscStopnia = 15.0; // Szerokość stopnia ustalamy na stałą wartość
}
```

#### Funkcja `wprowadzenieWymiarow`

Funkcja `wprowadzenieWymiarow` pobiera od użytkownika wymiary schodów (wysokość i długość). Dodatkowo, wyświetla ostrzeżenia, jeśli podane wymiary są mniejsze niż minimalne wartości, nawet jeśli nie przerywa działania programu. 

```cpp
void wprowadzenieWymiarow(double& wysokosc, double& dlugosc) {
    std::cout << "Podaj wysokość schodów (w cm): ";
    std::cin >> wysokosc;
    std::cout << "Podaj długość schodów (w cm): ";
    std::cin >> dlugosc;

    if (wysokosc < 15.0) {
        std::cerr << "Uwaga: Wysokość jest mniejsza od minimalnej zalecanej wartości 15 cm.\n";
    }
    if (dlugosc < 28.0) {
        std::cerr << "Uwaga: Długość jest mniejsza od minimalnej zalecanej wartości 28 cm.\n";
    }
}
```

### Testy

Poniżej znajdują się testy jednostkowe, które sprawdzają poprawność działania funkcji w różnych przypadkach. 

#### Testy dla Funkcji `obliczIloscStopni`

Testy sprawdzają, czy funkcja `obliczIloscStopni` zwraca poprawną liczbę stopni dla przykładowych wymiarów schodów, a także obsługuje przypadki, w których wymiary schodów są za małe, by uzyskać poprawną liczbę stopni.

```cpp
TEST(SchodoweTests, TestIloscStopni) {
    EXPECT_EQ(obliczIloscStopni(300, 400), 14);
    EXPECT_EQ(obliczIloscStopni(30.0, 60.0), 2);
    EXPECT_EQ(obliczIloscStopni(15.0, 30.0), 1);
    EXPECT_EQ(obliczIloscStopni(10.0, 20.0), 0); // Wymiary za małe, aby obliczyć liczbę stopni
}
```

#### Testy dla Funkcji `obliczWymiaryStopnia`

Testy sprawdzają poprawność obliczeń wymiarów stopni dla różnych wartości długości schodów oraz liczby stopni. Dodatkowo, test sprawdza, czy funkcja obsługuje przypadki, w których liczba stopni jest niepoprawna.
```cpp
TEST(SchodoweTests, TestWymiaryStopnia) {
    double dlugoscStopnia, szerokoscStopnia;
    obliczWymiaryStopnia(100.0, 4, dlugoscStopnia, szerokoscStopnia);

    EXPECT_DOUBLE_EQ(dlugoscStopnia, 25.0);
    EXPECT_DOUBLE_EQ(szerokoscStopnia, 15.0);

    obliczWymiaryStopnia(100.0, 0, dlugoscStopnia, szerokoscStopnia); // Test z niepoprawną liczbą stopni
    EXPECT_DOUBLE_EQ(dlugoscStopnia, 0);
    EXPECT_DOUBLE_EQ(szerokoscStopnia, 0);
}
```

### Podsumowanie

Program został uzupełniony o walidacje zapobiegające błędom wynikającym z niepoprawnych wartości wejściowych. Wszystkie funkcje przeszły testy jednostkowe, co potwierdza poprawność i niezawodność ich działania.


