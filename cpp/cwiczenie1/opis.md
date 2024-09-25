# Opis kodu sortowania bąbelkowego

Ten dokument opisuje prostą implementację algorytmu sortowania bąbelkowego w C++. Algorytm ten sortuje tablicę liczb całkowitych, przestawiając sąsiadujące elementy, jeśli są w złej kolejności.

## Struktura kodu

### 1. Funkcja sortująca
Kod wykorzystuje pętlę for oraz zmienia kolejność od najmniejszej do największej:
```cpp
void bubbleSort(std::vector<int>& arr) {
	int n =arr.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if(arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}
### 2. Główna funkcja
Zawiera wypisane liczby do posortowania, oraz wyświetla nieposortowane a później posortowane liczby:
```cpp
int main() {
	std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

	std::cout << "Nieposortowane:";
	printArray(arr);

	bubbleSort(arr);

	std::cout << "Posortowane:";
	printArray(arr);

	return 0;
}
