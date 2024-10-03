#include <iostream>
#include <vector>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

// Function to simulate if statements with a single user-provided value.
void testIf(int value, int userValue) {
    if (value == userValue) {}
    else if (value == userValue + 1) {}
    else if (value == userValue + 2) {}
    else if (value == userValue + 3) {}
    else if (value == userValue + 4) {}
    else if (value == userValue + 5) {}
    else if (value == userValue + 6) {}
    else if (value == userValue + 7) {}
    else if (value == userValue + 8) {}
    else if (value == userValue + 9) {}
}

// Function to simulate switch/case statements with a single user-provided value.
void testSwitch(int value, int userValue) {
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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
