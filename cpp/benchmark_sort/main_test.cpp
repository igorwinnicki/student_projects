#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

// Sort functions remain unchanged.
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

void quickSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;
    int pivot = vec[vec.size() / 2];
    std::vector<int> left, right;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] < pivot) left.push_back(vec[i]);
        else if (vec[i] > pivot) right.push_back(vec[i]);
    }
    quickSort(left);
    quickSort(right);
    vec.clear();
    vec.insert(vec.end(), left.begin(), left.end());
    vec.push_back(pivot);
    vec.insert(vec.end(), right.begin(), right.end());
}

// Function to verify if the vector is sorted.
bool isSorted(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i - 1] > vec[i]) return false;
    }
    return true;
}

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

TEST(BenchmarkTest, QuickSortBenchmark) {
    std::vector<int> original(1000);
    std::srand(std::time(0)); // Seed random generator the same way

    for (int i = 0; i < 10000; i++) {
        std::generate(original.begin(), original.end(), std::rand);
        std::vector<int> vec = original;

        auto start = std::chrono::high_resolution_clock::now();
        quickSort(vec);
        auto end = std::chrono::high_resolution_clock::now();

        EXPECT_TRUE(isSorted(vec)) << "QuickSort failed on iteration " << i;

        std::chrono::duration<double> elapsed_seconds = end - start;
        if (i == 0) { // Print time for the first test only.
            std::cout << "Czas sortowania QuickSort: " << elapsed_seconds.count() << "s\n";
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
