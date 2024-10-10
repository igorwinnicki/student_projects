# Benchmark porównanie quicksort i bubblesort
#### Lista funkcji 
                
+ Funkcja bąbelkowa.
    + Pozostaje nie zmieniona w porównaniu do orginalnej funkcji.

```cpp
  void bubbleSort(std::vector<int>& vec) {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < vec.size() - 1; i++) {
            if (vec[i] > vec[i + 1]) {
                std::swap(vec[i], vec[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}
```
+ Funkcja quicksort.
    + Również pozostaje nie zmieniona w porównaniu do orginalnej funkcji.

```cpp
  void bubbleSort(std::vector<int>& vec) {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < vec.size() - 1; i++) {
            if (vec[i] > vec[i + 1]) {
                std::swap(vec[i], vec[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}
```
+ Funkcja króra sprawdza czy wektor na pewno jest posortowany.

```cpp
  bool isSorted(const std::vector<int>& vec) {
      for (size_t i = 1; i < vec.size(); i++) {
          if (vec[i - 1] > vec[i]) return false;
      }
      return true;
  }
```
+ Przeprowadzane są testy sortowania bąbelkowego.
  + Sortowania bąbelkowego.

```cpp
  TEST(BenchmarkTest, BubbleSortBenchmark) {
    std::vector<int> original(1000);
    std::srand(std::time(0));

    for (int i = 0; i < 10000; i++) {
        std::generate(original.begin(), original.end(), std::rand);
        std::vector<int> vec = original;

        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(vec);
        auto end = std::chrono::high_resolution_clock::now();

        EXPECT_TRUE(isSorted(vec)) << "BubbleSort failed on iteration " << i;

        std::chrono::duration<double> elapsed_seconds = end - start;
        if (i == 0) { // Print time for the first test only.
            std::cout << "Czas sortowania BubbleSort: " << elapsed_seconds.count() << "s\n";
        }
    }
}
```
  + Sortowania quicksort.

```cpp
  TEST(BenchmarkTest, BubbleSortBenchmark) {
    std::vector<int> original(1000);
    std::srand(std::time(0));

    for (int i = 0; i < 10000; i++) {
        std::generate(original.begin(), original.end(), std::rand);
        std::vector<int> vec = original;

        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(vec);
        auto end = std::chrono::high_resolution_clock::now();

        EXPECT_TRUE(isSorted(vec)) << "BubbleSort failed on iteration " << i;

        std::chrono::duration<double> elapsed_seconds = end - start;
        if (i == 0) { // Print time for the first test only.
            std::cout << "Czas sortowania BubbleSort: " << elapsed_seconds.count() << "s\n";
        }
    }
}
```
+ Przykład wykonanego kodu

![Tekst](sort.png)

Z wykonanego kodu wynika, że quicksort jest szybszym sposobem sortowania niz bubblesort
