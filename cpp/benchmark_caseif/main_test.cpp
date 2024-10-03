#include <iostream>
#include <vector>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

// Function to simulate if statements.
void testIf(int value) {
    if (value == 0) {}
    else if (value == 1) {}
    else if (value == 2) {}
    else if (value == 3) {}
    else if (value == 4) {}
    else if (value == 5) {}
    else if (value == 6) {}
    else if (value == 7) {}
    else if (value == 8) {}
    else if (value == 9) {}
}

// Function to simulate switch/case statements.
void testSwitch(int value) {
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

TEST(BenchmarkTest, IfStatementBenchmark) {
    std::srand(std::time(0));
    for (int i = 0; i < 10000; i++) {
        int randomValue = std::rand() % 10;

        auto start = std::chrono::high_resolution_clock::now();
        testIf(randomValue);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        if (i == 0) { // Print time for the first test only.
            std::cout << "Czas wykonania testIf: " << elapsed_seconds.count() << "s\n";
        }
    }
}

TEST(BenchmarkTest, SwitchCaseBenchmark) {
    std::srand(std::time(0));
    for (int i = 0; i < 10000; i++) {
        int randomValue = std::rand() % 10;

        auto start = std::chrono::high_resolution_clock::now();
        testSwitch(randomValue);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        if (i == 0) { // Print time for the first test only.
            std::cout << "Czas wykonania testSwitch: " << elapsed_seconds.count() << "s\n";
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
