/*
Lab: Basic Math
Updated By: [Your Name]
Date: [Today's Date]
CSCI 111 - Foundations of Computer Science
Semester: [Current Semester]

Read and Solve: https://open.kattis.com/problems/dfyrirdreki

Algorithm steps:
See hints in the figure of problem statement.
   1. Read 3 coefficients (a, b, c) of a quadratic equation
   2. Calculate b^2 - 4ac as the discriminant
   3. if the discriminant is negative, print 0 - no real roots
   4. if the discriminant is zero, print 1 - one real root
   5. if the discriminant is positive, print 2 - two real roots
*/

#include <iostream>
#include <cmath>
#include "roots.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Your solution here
    // declare variables to store input data and answer
    int a, b, c;
    long long discriminant;
    cin >> a >> b >> c;

    // calculate the discriminant
    discriminant = find_discriminant(a, b, c);
    // FIXME1: determine the number of real roots using function and print the result
    return 0;
}
