/*
Kattis - Triangle Area Problem

Updated By: FIXME
Date: FIXME

Problem Statement: https://open.kattis.com/problems/triarea
Algorithm steps:
1. Design a struct to store triangle info
2. Read height and width into struc object
3. Find area of triangle using 1/2 x base x height
4. Print the area upto 7 decimal points
*/

#include <iostream>
#include <iomanip>
#include "triangle.hpp"

using namespace std;

int main()
{
    triangle::Triangle *t = new triangle::Triangle;
    // FIXME1 - read height and base from stdio into t
    cout << fixed << setprecision(7);
    // FIXME2 - output area of triangle using find_area function
    // FIXME3 - free memory allocated for t
    return 0;
}
