#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Wybieramy element skrajny jako pivot
    int i = low - 1;       // Indeks mniejszego elementu

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Zamieniamy elementy mniejsze od pivotu na lewą stronę
        }
    }
    swap(arr[i + 1], arr[high]); // Przesuwamy pivot na odpowiednie miejsce
    return i + 1; // Zwracamy indeks pivotu
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Znajdujemy punkt podziału

        quickSort(arr, low, pi - 1);  // Sortujemy lewą część
        quickSort(arr, pi + 1, high); // Sortujemy prawą część
    }
}

int main() {
    // Tworzymy wektor z 10000 losowymi liczbami
    vector<int> vec(10000); 
    srand(time(0)); // Inicjalizacja generatora liczb losowych
    generate(vec.begin(), vec.end(), rand);

    int n = vec.size();

    // Początek pomiaru czasu
    auto start = chrono::high_resolution_clock::now();

    // Sortowanie wektora przy użyciu QuickSort
    quickSort(vec, 0, n - 1);

    // Koniec pomiaru czasu
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";

    // Sprawdzanie, czy tablica jest posortowana
    bool sorted = is_sorted(vec.begin(), vec.end());
    if (sorted) {
        cout << "Tablica została poprawnie posortowana.\n";
    } else {
        cout << "Błąd: Tablica nie jest poprawnie posortowana.\n";
    }

    return 0;
}
