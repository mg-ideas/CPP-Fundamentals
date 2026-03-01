// Program to test functions defined in my_math.cpp file

#include <iostream>
#include <cmath>
#include <cassert>
#include "../include/my_math.hpp"
using namespace std;

const float EPSILON = 1e-6; // accuracy upto 6 decimal points

void test_square_root()
{
    float num = 16.0;
    float expected = 4.0;
    float result = square_root(num);
    assert(fabs(result - expected) <= EPSILON);
}

void test_log_base_2()
{
    float num = 1024;
    float expected = 10;
    float result = log_base_2(num);
    assert(fabs(result - expected) <= EPSILON);
}

// FIXME - define test functions for rest of the functions defined in my_math.cpp
