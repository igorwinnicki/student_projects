#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include <random>
#include <gtest/gtest.h>

double calculateSteps(double wysokosc, double dlugosc) {
    double minWysokosc = 15.0;
    double minDlugosc = 28.0;
    
    int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc);
    int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc);
    
    return std::min(iloscStopniWysokosc, iloscStopniDlugosc);
}

TEST(BenchmarkTest, StairCalculationBenchmark) {
    std::vector<double> wysokosci(1000);
    std::vector<double> dlugosci(1000);
    
    // Generuj losowe dane
    std::default_random_engine generator;
    std::uniform_real_distribution<double> height_distribution(150.0, 170.0);
    std::uniform_real_distribution<double> length_distribution(280.0, 300.0);

    for (int i = 0; i < 1000; ++i) {
        wysokosci[i] = height_distribution(generator);
        dlugosci[i] = length_distribution(generator);
    }

    for (int i = 0; i < 10000; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        
        for (size_t j = 0; j < wysokosci.size(); ++j) {
            calculateSteps(wysokosci[j], dlugosci[j]);
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        
        if (i == 0) { // Print time for the first test only.
            std::cout << "Czas obliczania ilości stopni: " << elapsed_seconds.count() << "s\n";
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
