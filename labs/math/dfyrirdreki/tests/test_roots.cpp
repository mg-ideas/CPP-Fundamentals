#include "../src/roots.h"
#include <iostream>
#include <cassert>

using namespace std;

// Test function for find_discriminant
void test_find_discriminant()
{
    int ans = find_discriminant(1, 5, 6);
    int expected = 1;
    assert(ans == expected);
}

// FIXME1 - define 2 more test functions for find_discriminant

// Test function for find_roots
void test_find_roots()
{
    int ans = find_roots(-1);
    int expected = 0;
    assert(ans == expected);
}

// FIXME2 - define 2 more test functions for find_roots

int main()
{
    cerr << "Roots Function Test Runner" << endl;
    test_find_discriminant();
    test_find_roots();
    // FIXME3: call the rest of the test functions
    cerr << "All test cases passed!" << endl;
    return 0;
}