# Analiza wydajności: Porównanie konstrukcji if i switch

### Cel dokumentacji
Celem niniejszej dokumentacji jest przeprowadzenie szczegółowej analizy wydajności dwóch popularnych konstrukcji warunkowych w języku C++: if oraz switch. Analizowane będą różnice w czasie wykonania obu metod w kontekście porównywania wartości liczbowych.

#### Funkcja if
Funkcja testIf wykorzystuje szereg instrukcji if do sprawdzania, czy przekazana liczba (value) odpowiada jednej z dziesięciu wartości w wektorze (values).

```cpp

void testIf(int value, const std::vector<int>& values) {
    if (value == values[0]) {}
    else if (value == values[1]) {}
    else if (value == values[2]) {}
    else if (value == values[3]) {}
    else if (value == values[4]) {}
    else if (value == values[5]) {}
    else if (value == values[6]) {}
    else if (value == values[7]) {}
    else if (value == values[8]) {}
    else if (value == values[9]) {}
}
```
#### Funkcja case

Funkcja testSwitch implementuje strukturę switch, która w podobny sposób sprawdza wartość liczby value, porównując ją z wartościami od 0 do 9.

```cpp
void testSwitch(int value, const std::vector<int>& values) {
    switch (value) {
        case 0: break;
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: break;
        case 7: break;
        case 8: break;
        case 9: break;
        default: break;
    }
}
```
### Przeprowadzanie testów wydajności
#### Test dla instrukcji if

W teście if, użytkownik wprowadza jedną wartość, która jest następnie używana do pomiaru czasu wykonania funkcji testIf w pętli przez 10,000 iteracji. Czas wykonania każdej iteracji jest sumowany, a wynik przedstawiany użytkownikowi.

```cpp
TEST(BenchmarkTest, IfStatementBenchmark) {
    std::srand(std::time(0));

    // Pobranie jednej wartości od użytkownika
    int userValue;
    std::cout << "Podaj jedną wartość do testu if: ";
    std::cin >> userValue;

    // Zmienna do sumowania czasu
    std::chrono::duration<double> total_time_if(0);

    for (int i = 0; i < 10000; i++) {
        int randomValue = std::rand() % 10;

        auto start = std::chrono::high_resolution_clock::now();
        testIf(randomValue, userValue);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        total_time_if += elapsed_seconds;
    }

    // Wyświetlenie sumarycznego czasu dla wszystkich iteracji
    std::cout << "Suma czasu wykonania testIf dla 10000 iteracji: " << total_time_if.count() << "s\n";
}
```
![Tekst](nowe.png)
#### Test dla instrukcji switch

Podobnie jak w przypadku if, test switch mierzy czas wykonania funkcji testSwitch na tej samej liczbie iteracji. Użytkownik również podaje wartość, a wyniki są przedstawiane w analogiczny sposób.
```cpp
TEST(BenchmarkTest, SwitchCaseBenchmark) {
    std::srand(std::time(0));

    // Pobranie jednej wartości od użytkownika
    int userValue;
    std::cout << "Podaj jedną wartość do testu switch/case: ";
    std::cin >> userValue;

    // Zmienna do sumowania czasu
    std::chrono::duration<double> total_time_switch(0);

    for (int i = 0; i < 10000; i++) {
        int randomValue = std::rand() % 10;

        auto start = std::chrono::high_resolution_clock::now();
        testSwitch(randomValue, userValue);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        total_time_switch += elapsed_seconds;
    }

    // Wyświetlenie sumarycznego czasu dla wszystkich iteracji
    std::cout << "Suma czasu wykonania testSwitch dla 10000 iteracji: " << total_time_switch.count() << "s\n";
}
```

### Wyniki

W wyniku przeprowadzonych testów, na podstawie analizy czasów wykonania obu funkcji, można zauważyć, że konstrukcja switch wykazuje marginalnie szybszy czas wykonania w porównaniu do złożonej serii instrukcji if. Takie wyniki mogą być istotne w kontekście wydajności programów, w których wielokrotne sprawdzenia warunków są kluczowe dla efektywności działania.
### Wnioski

Na podstawie przeprowadzonych badań można stwierdzić, że w przypadkach, gdzie zachodzi potrzeba wielokrotnego sprawdzania warunków na wartościach całkowitych, konstrukcja switch może okazać się bardziej efektywna od serii instrukcji if. Należy jednak pamiętać, że w praktycznych zastosowaniach wybór odpowiedniej konstrukcji powinien być również uzależniony od kontekstu i czytelności kodu.


![Tekst](nowe1.png)
