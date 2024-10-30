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

----Kompilacja programu testujacego----
/usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/Scrt1.o: in function `_start':
(.text+0x1b): undefined reference to `main'
collect2: error: ld returned 1 exit status
/usr/bin/ld: /tmp/cc4Pj0Fi.o: in function `SchodoweTests_TestIloscStopni_Test::TestBody()':
main_test.cpp:(.text+0x40): undefined reference to `obliczIloscStopni(double, double)'
/usr/bin/ld: main_test.cpp:(.text+0x117): undefined reference to `obliczIloscStopni(double, double)'
/usr/bin/ld: main_test.cpp:(.text+0x1ee): undefined reference to `obliczIloscStopni(double, double)'
/usr/bin/ld: /tmp/cc4Pj0Fi.o: in function `SchodoweTests_TestWymiaryStopnia_Test::TestBody()':
main_test.cpp:(.text+0x3df): undefined reference to `obliczWymiaryStopnia(double, int, double&, double&)'
collect2: error: ld returned 1 exit status
---Kompilacja testow ukonczona----
---Uruchamianie programu testujacego---
chmod: cannot access 'main_test': No such file or directory
./kompiluj_test.sh: 15: ./main_test: not found
---Zakonczono program testujacy---
