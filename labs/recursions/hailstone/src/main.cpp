/*
Kattis Problem - Watch Out For Those Hailsontes!
Updated By: FIXME
Date: FIXME

Problem Statement: https://open.kattis.com/problems/hailstone

Algorithm steps:
1. Define a recursive function, say h_sum, with the following cases:
    a. base case: if n = 1, answer is 1
    b. general cases:
        i. if n is even, the sequence is n + h_sum(n/2)
        ii. if n is odd, the sequence is n + h_sum(3n + 1)
2. Read an integer n from input
3. Call the recursive function h with n and print the resulting sequence
*/

#include <iostream>
#include "hailstone.hpp"
using namespace std;

int main()
{
    // FXIME1 - declare a pointer to uint64_t (aka: unsigned long long int) and allocate memory for it
    // FIXME2 - read an integer from input and store it in the allocated memory
    // FIXME3 - call the hailstone::h_sum function with the value read from input and print the result
    // FIXME4 - deallocate the memory allocated for the pointer
    return 0;
}