#include <iostream>
#include <cassert>
#include <string>
using namespace std;

string odd_or_even(const int unsigned number)
{
    // FIXED 4: if the number divided by 2 has 0 remainder, return 'even'
    // otherwise, return 'odd'
    if (number%2 == 0 )
        return "even";
    else
        return "odd";
}

string answer(const int unsigned stone)
{
    string evenorodd = odd_or_even(stone);
    if (evenorodd == "odd")
        return "Alice";
    else
        return "Bob";
}

void test_odd_or_even()
{
    int unsigned number;
    number = 99999;
    assert(odd_or_even(number) == "odd");
    assert(odd_or_even(100) == "even");
    assert(odd_or_even(5) == "odd");
    // FIXED 5: Write 2nd test case
    // FIXED 6: Write 3rd test case
    cerr << "All test cases passed for odd_or_even() !\n";
}
void test_answer()
{
    assert(answer(2) == "Bob");
    assert(answer(1) == "Alice");
    assert(answer(22) == "Bob");
}
// FIXED 7: Write a function to test answer function using assert function
// Write at least 3 test cases
