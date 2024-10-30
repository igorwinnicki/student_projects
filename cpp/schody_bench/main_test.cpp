// #include <gtest/gtest.h>
// #include "functions.cpp"

// // Prototypy funkcji
// double obliczIloscStopni(double wysokosc, double dlugosc);
// void obliczWymiaryStopnia(double dlugosc, int iloscStopni, double& dlugoscStopnia, double& szerokoscStopnia);

// // Testy jednostkowe
// TEST(SchodoweTests, TestIloscStopni) {
//     EXPECT_EQ(obliczIloscStopni(300, 400), 14);
//     EXPECT_EQ(obliczIloscStopni(30.0, 60.0), 2);
//     EXPECT_EQ(obliczIloscStopni(15.0, 30.0), 1);
// }

// TEST(SchodoweTests, TestWymiaryStopnia) {
//     double dlugoscStopnia, szerokoscStopnia;
//     obliczWymiaryStopnia(100.0, 4, dlugoscStopnia, szerokoscStopnia);
    
//     EXPECT_DOUBLE_EQ(dlugoscStopnia, 25.0);
//     EXPECT_DOUBLE_EQ(szerokoscStopnia, 15.0);
// }

// // Uruchomienie testów
// int main(int argc, char **argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
#include <gtest/gtest.h>
#include "functions.h"

// Testy jednostkowe
TEST(SchodoweTests, TestIloscStopni) {
    EXPECT_EQ(obliczIloscStopni(300, 400), 14);
    EXPECT_EQ(obliczIloscStopni(30.0, 60.0), 2);
    EXPECT_EQ(obliczIloscStopni(15.0, 30.0), 1);
}

TEST(SchodoweTests, TestWymiaryStopnia) {
    double dlugoscStopnia, szerokoscStopnia;
    obliczWymiaryStopnia(100.0, 4, dlugoscStopnia, szerokoscStopnia);
    
    EXPECT_DOUBLE_EQ(dlugoscStopnia, 25.0);
    EXPECT_DOUBLE_EQ(szerokoscStopnia, 15.0);
}

// Uruchomienie testów
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
