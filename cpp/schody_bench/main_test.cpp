// #include <gtest/gtest.h>
#include "functions.cpp"
#include <gtest/gtest.h>
#include "functions.h"

// Testy jednostkowe
TEST(SchodoweTests, TestIloscStopni) {
    EXPECT_EQ(obliczIloscStopni(300, 400), 14);
    EXPECT_EQ(obliczIloscStopni(30.0, 60.0), 2);
    EXPECT_EQ(obliczIloscStopni(15.0, 30.0), 1);
}

TEST(SchodoweTests, TestWymiaryStopnia) {
    double dlugoscStopnia, wysokoscStopnia;
obliczWymiaryStopnia(100.0, 60.0, 4, dlugoscStopnia, wysokoscStopnia);
    
    EXPECT_DOUBLE_EQ(dlugoscStopnia, 25.0);
    EXPECT_DOUBLE_EQ(wysokoscStopnia, 15.0);
}

// Uruchomienie testów
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
