# Dokumentacja Programu do Obliczania Schodów

### Cel Dokumentacji

Celem tej dokumentacji jest przedstawienie szczegółów implementacji programu, który oblicza liczbę stopni schodów na podstawie podanych przez użytkownika wymiarów schodów (wysokość i długość), a także szczegółowe wymiary każdego stopnia. Dokumentacja obejmuje również opis testów jednostkowych, które weryfikują poprawność działania programu.

---

## Opis Funkcji

### 1. `obliczIloscStopni`

Funkcja `obliczIloscStopni` oblicza maksymalną liczbę stopni, która może być wygenerowana na podstawie wymiarów schodów podanych przez użytkownika, przy czym każdy stopień ma spełniać minimalne i maksymalne wymagania dotyczące wysokości i długości.

//kod

- **Parametry**:
  - `wysokosc` - całkowita wysokość schodów w centymetrach (double).
  - `dlugosc` - całkowita długość schodów w centymetrach (double).

- **Zwracana wartość**:
  - Zwraca liczbę stopni jako wartość całkowitą (int), która spełnia wymagania minimalnych wymiarów stopni. 
  - Jeśli wymiary są zbyt małe, zwraca wartość `-1`, co oznacza brak możliwości wygenerowania schodów.

---

### 2. `obliczWymiaryStopnia`

Funkcja `obliczWymiaryStopnia` oblicza szczegółowe wymiary pojedynczego stopnia na podstawie całkowitych wymiarów schodów oraz liczby stopni wygenerowanej przez `obliczIloscStopni`.

//kod

- **Parametry**:
  - `dlugosc` - całkowita długość schodów w centymetrach (double).
  - `wysokosc` - całkowita wysokość schodów w centymetrach (double).
  - `iloscStopni` - liczba stopni wygenerowana przez funkcję `obliczIloscStopni` (int).
  - `dlugoscStopnia` - referencja do zmiennej przechowującej długość pojedynczego stopnia (double).
  - `wysokoscStopnia` - referencja do zmiennej przechowującej wysokość pojedynczego stopnia (double).

- **Opis działania**:
  Funkcja dzieli długość i wysokość schodów przez liczbę stopni, uzyskując wymiary każdego stopnia osobno.

---

### 3. `wprowadzenieWymiarow`

Funkcja `wprowadzenieWymiarow` pobiera od użytkownika wysokość i długość schodów.

//kod

- **Parametry**:
  - `wysokosc` - referencja do zmiennej przechowującej wartość wysokości schodów w centymetrach (double).
  - `dlugosc` - referencja do zmiennej przechowującej wartość długości schodów w centymetrach (double).

- **Opis działania**:
  Funkcja wyświetla komunikaty dla użytkownika i zapisuje wprowadzone wartości w odpowiednich zmiennych.

---

## Plik `main.cpp`

Główna logika programu znajduje się w `main.cpp`, gdzie wykonywane są operacje pobierania danych od użytkownika, obliczania liczby stopni, a także wyświetlania wymiarów każdego stopnia.

//kod

---

## Testy

Testy jednostkowe sprawdzają, czy funkcje `obliczIloscStopni` i `obliczWymiaryStopnia` działają zgodnie z założeniami programu. Testy znajdują się w pliku `main_test.cpp`.

### Testy do `obliczIloscStopni`

Testy funkcji `obliczIloscStopni` sprawdzają poprawność obliczeń liczby stopni przy różnych wartościach wysokości i długości schodów, a także reakcję funkcji na wartości niemożliwe do przetworzenia.

//kod

### Testy do `obliczWymiaryStopnia`

Testy funkcji `obliczWymiaryStopnia` weryfikują poprawność obliczeń długości i wysokości pojedynczego stopnia na podstawie liczby stopni oraz całkowitych wymiarów schodów.

//kod

## Podsumowanie

Program do obliczania schodów pozwala użytkownikowi wprowadzić wymiary schodów i oblicza szczegółowe dane o liczbie i wymiarach stopni. Program został przetestowany przy użyciu testów jednostkowych, co zapewnia poprawność działania w szerokim zakresie wartości, w tym przy wartościach niemożliwych do przetworzenia.
