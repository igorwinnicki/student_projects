#include <gtest/gtest.h>
#include "functions.cpp"

TEST(FizzBuzzTest, DivisibleBy3) {
    EXPECT_EQ(fizzBuzz(3), "Fizz");
    EXPECT_EQ(fizzBuzz(6), "Fizz");
    EXPECT_EQ(fizzBuzz(9), "Fizz");
}

TEST(FizzBuzzTest, DivisibleBy5) {
    EXPECT_EQ(fizzBuzz(5), "Buzz");
    EXPECT_EQ(fizzBuzz(10), "Buzz");
    EXPECT_EQ(fizzBuzz(20), "Buzz");
}

TEST(FizzBuzzTest, DivisibleBy3And5) {
    EXPECT_EQ(fizzBuzz(15), "FizzBuzz");
    EXPECT_EQ(fizzBuzz(30), "FizzBuzz");
    EXPECT_EQ(fizzBuzz(45), "FizzBuzz");
}

TEST(FizzBuzzTest, NotDivisibleBy3Or5) {
    EXPECT_EQ(fizzBuzz(1), "1");
    EXPECT_EQ(fizzBuzz(2), "2");
    EXPECT_EQ(fizzBuzz(4), "4");
}

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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
