#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h" // FIXME: adjust the path as needed
#include "../src/fileio.h"

TEST_CASE("Testing read_data function")
{
    SUBCASE("Sub Case 1: Valid file with numbers")
    {
        // assume data/input1.txt exists with 7 test data
        vector<int> numbers(7, 0);
        string input_file = "data/input1.txt"; // make sure this file exists with test data
        read_data(numbers, input_file);
        CHECK(numbers.size() == 7); // assuming input1.txt has 7 numbers
        CHECK(numbers[0] == 100);   // adjust expected values as per your input test file
        CHECK(numbers[1] == 10);
    }
    // FIXME7: Write 2nd test case for read_data function
}

TEST_CASE("Testing find_min function")
{
    SUBCASE("Sub Case 1: Distinct values")
    {
        vector<int> numbers = {5, 3, 8, 1, 4};
        int expected = 1;
        int result = find_min(numbers);
        CHECK(result == expected);
    }
    // FIXME8: Write 2nd test case for find_min function
}

TEST_CASE("Testing find_range function")
{
    SUBCASE("Sub Case 1: Distinct values")
    {
        vector<int> numbers = {5, 3, 8, 1, 4};
        int expected = 7; // 8 - 1
        int result = find_range(numbers);
        CHECK(result == expected);
    }
    // FIXME9: Write 2nd test case for find_range function
}

TEST_CASE("Testing find_mean function")
{
    SUBCASE("Sub Case 1: Distinct values")
    {
        vector<int> numbers = {5, 3, 8, 1, 4};
        float expected = 4.2f; // (5+3+8+1+4)/5
        float result = find_mean(numbers);
        CHECK(fabs(result - expected) <= EPSILON);
    }
    // FIXME10: Write 2nd test case for find_mean function
}

TEST_CASE("Testing find_median function")
{
    SUBCASE("Sub Case 1: Odd number of elements")
    {
        vector<int> numbers = {5, 3, 8, 1, 4};
        float expected = 4.0f; // sorted: {1,3,4,5,8}
        float result = find_median(numbers);
        CHECK(fabs(result - expected) <= EPSILON);
    }
    // FIXME11: Write 2nd test case for find_median function
}
