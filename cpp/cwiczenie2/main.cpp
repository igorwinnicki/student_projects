#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

TEST(BenchmarkTest, QuickSortBenchmark) {
    std::vector<int> vec(10000);
    std::srand(std::time(0));
    std::generate(vec.begin(), vec.end(), std::rand);

    auto start = std::chrono::high_resolution_clock::now();
    quick_sort(vec, 0, vec.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


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
