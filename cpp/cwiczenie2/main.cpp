#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include "gtest/gtest.h"

using namespace std;

// QuickSort function
void quick_sort(int *tab, int lewy, int prawy) {
    if (prawy <= lewy) return;

    int i = lewy - 1, j = prawy + 1;
    int pivot = tab[(lewy + prawy) / 2]; // Choosing the pivot

    while (true) {
        while (pivot > tab[++i]);
        while (pivot < tab[--j]);
        
        if (i <= j)
            swap(tab[i], tab[j]);
        else
            break;
    }

    if (j > lewy)
        quick_sort(tab, lewy, j);
    if (i < prawy)
        quick_sort(tab, i, prawy);
}

// Test for QuickSort performance
TEST(BenchmarkTest, QuickSortBenchmark) {
    const int n = 10000; // Size of the vector
    std::vector<int> vec(n); // Create a vector with 10000 random numbers
    std::srand(static_cast<unsigned int>(std::time(0))); // Initialize random number generator
    std::generate(vec.begin(), vec.end(), std::rand);

    // Convert vector to array for quick_sort function
    int* tab = vec.data();

    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    quick_sort(tab, 0, n - 1); // Sort the array

    // End measuring time
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <ctime>
// #include "gtest/gtest.h"
// #include <chrono>
// using namespace std;


// void quick_sort(int *tab, int lewy, int prawy)
// {
// 	if(prawy <= lewy) return;
	
// 	int i = lewy - 1, j = prawy + 1, 
// 	pivot = tab[(lewy+prawy)/2]; //wybieramy punkt odniesienia
	
// 	while(1)
// 	{
// 		while(pivot>tab[++i]);

// 		while(pivot<tab[--j]);

// 		if( i <= j)
// 			swap(tab[i],tab[j]);
// 		else
// 			break;
// 	}

// 	if(j > lewy)
// 	quick_sort(tab, lewy, j);
// 	if(i < prawy)
// 	quick_sort(tab, i, prawy);
// }


// // Test wydajności sortowania QuickSort
// TEST(BenchmarkTest, QuickSortBenchmark) {
//     std::vector<int> vec(10000); // Tworzymy wektor z 10000 losowymi liczbami
//     std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych
//     std::generate(vec.begin(), vec.end(), std::rand);

//     // Początek pomiaru czasu
//     auto start = std::chrono::high_resolution_clock::now();

//     quick_sort(tab,0, n-1); // Sortujemy wektor

//     // Koniec pomiaru czasu
//     auto end = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> elapsed_seconds = end - start;

//     std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
// }

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }


// int main()
// {
// 	int *tab, n;
//   	cin>>n;
//   	tab = new int [n]; //przydzielenie pamięci na elementy tablicy
//   	//wczytanie liczb
//   	for(int i=0;i<n;i++)
//     	cin>>tab[i];
 
//   	quick_sort(tab,0, n-1);
 
//   	for(int i=0;i<n;i++)
//           cout<<tab[i]<<" ";
 
//   	cin.ignore();
//   	cin.get();
//   	return 0;
// }
