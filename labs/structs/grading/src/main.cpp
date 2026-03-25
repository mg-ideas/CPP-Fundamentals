/*
Kattis Grading Problem - https://open.kattis.com/problems/grading

Updated By: FIXME
Date: FIXME

Problem Statement: https://open.kattis.com/problems/grading
Algorithm steps:
1. Design a struct to store 5 grading criteria and exam score info
2. Read 5 grading criteria and exam score into struct object
3. Find final grade using the following rules:
    i. >= a% is A
    ii. >= b% is B
    iii. >= c% is C
    iv. >= d% is D
    v. >= e% is E
    vi. < e% is F
4. Print the final grade
*/

#include <iostream>
#include "grading.hpp"
using namespace std;

int main()
{
    Grading *g = new Grading;
    // FIXME1 - read 5 grading criteria and grade from stdio into g #FIXED#
    cin >> g->a >> g->b >> g->c >> g->d >> (*g).e;
    // FIXME2 - read grade into g's exam_score field
    cout << g->find_grade() << endl;
    // free memory allocated for g
    delete g;
    return 0;
}