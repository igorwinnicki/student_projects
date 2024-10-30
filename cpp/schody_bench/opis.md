# Dokumentacja Schodów

### Cel Dokumentacji

Celem tej dokumentacji jest przedstawienie implementacji oraz testów funkcji służących do obliczania liczby oraz wymiarów stopni schodów. Program przyjmuje wysokość i długość schodów, a następnie oblicza liczbę stopni oraz ich wymiary.

### Opis Funkcji

#### Funkcja `obliczIloscStopni`

Funkcja oblicza maksymalną liczbę stopni schodów na podstawie ich całkowitej wysokości i długości.

//kod

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

