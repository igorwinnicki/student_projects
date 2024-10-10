# Benchmark porównanie if i case 
                
+ Functions.cpp.
    + To bardzo prosta funkcja sprawdzająca czy liczby podzielne są przez 5 i 3 lub tylko przez 3 bądż przez 5.

```cpp
std::string fizzBuzz(int number) {
    if (number % 3 == 0 && number % 5 == 0) {
        return "FizzBuzz";
    } else if (number % 3 == 0) {
        return "Fizz";
    } else if (number % 5 == 0) {
        return "Buzz";
    } else {
        return std::to_string(number);
    }
}
```
+ Testy.
    + Pierwszy test sprawdza czy liczba podzielna przez 3 przyniesie spodziewany efekt - "Fizz".

```cpp
TEST(FizzBuzzTest, DivisibleBy3) {
    EXPECT_EQ(fizzBuzz(3), "Fizz");
    EXPECT_EQ(fizzBuzz(6), "Fizz");
    EXPECT_EQ(fizzBuzz(9), "Fizz");
}
```

    + Drugi test sprawdza czy liczba podzielna przez 5 przyniesie spodziewany efekt - "Buzz".

```cpp
TEST(FizzBuzzTest, DivisibleBy5) {
    EXPECT_EQ(fizzBuzz(5), "Buzz");
    EXPECT_EQ(fizzBuzz(10), "Buzz");
    EXPECT_EQ(fizzBuzz(20), "Buzz");
}
```

    + Trzeci test sprawdza czy liczba podzielna przez 5 i 3 przyniesie spodziewany efekt - "FizzBuzz".

```cpp
TEST(FizzBuzzTest, DivisibleBy3And5) {
    EXPECT_EQ(fizzBuzz(15), "FizzBuzz");
    EXPECT_EQ(fizzBuzz(30), "FizzBuzz");
    EXPECT_EQ(fizzBuzz(45), "FizzBuzz");
}
```

    + Czwarty test sprawdza czy liczba niepodzielna ani przez 5 ani 3 przyniesie spodziewany efekt - a raczej jego brak.

```cpp
TEST(FizzBuzzTest, NotDivisibleBy3Or5) {
    EXPECT_EQ(fizzBuzz(1), "1");
    EXPECT_EQ(fizzBuzz(2), "2");
    EXPECT_EQ(fizzBuzz(4), "4");
}
```


    + Piąty test to wszystkie poprzednie 4 testy połączone i zautomatyzowane.

```cpp
TEST(FizzBuzzTest, AutomaticTest) {
    for (int i = 1; i <= 100; ++i) {
        std::string expected;
        if (i % 3 == 0 && i % 5 == 0) {
            expected = "FizzBuzz";
        } else if (i % 3 == 0) {
            expected = "Fizz";
        } else if (i % 5 == 0) {
            expected = "Buzz";
        } else {
            expected = std::to_string(i);
        }
        EXPECT_EQ(fizzBuzz(i), expected) << "Failed for number: " << i;
    }
}
```
