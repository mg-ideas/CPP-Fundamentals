/*
Kattis - Triangle Area Problem
Function and Unit Testing with Doctest
Updated By: FIXME
CSCI 111
Date: FIXME

Read and solve Triangle Area problem: https://open.kattis.com/problems/triarea

Algorithm:
    1. Read height and base of a right triangle
    2. Define a function to find and return area given height and base of a right triangle
        a. Area is given by the equation: (Base * Height)/2
    3. Call the function to find and print the result
    4. Write a test function to test the area function implemented in step 2
*/

#include <iostream>
#include <cstdio>
#include <string>
// #include <iomanip>
#include "triarea.h"

using namespace std;

int main(int argc, char **argv)
{
    unsigned height, base;
    float answer;
    // read height and base into corresponding variables
    cin >> height >> base;
    // FIXME1: Call area function passing proper arguments
    // store the returned result into answer variable
    answer = 0.0f;
    // print answer
    printf("%.7f\n", answer);
    // alternative way to print answer with 7 decimal places
    // cout << fixed << setprecision(7) << answer << endl;
    return 0;
}