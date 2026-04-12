/*
Kattis - Overnight Oats
STL - Deque
Updated By: FIXME
CSCI 111
Date: FIXME

Read and solve The Last Problem: https://open.kattis.com/problems/overnightoats

Help Julia avoid eating explired overnight oats!

Algorithm:
        1. read number of days to simulate, N
        2. read number of self life days, X
        3. iterate through the number of days, N
            - read what Julia does each day: ADD, EAT, or PASS
                - ADD: prepare a cup of overnight oats
                - EAT: eat the oldest cup of overnight oats
                - PASS: do nothing
            - simulate the activity using deque
                - if ADD: add the current day to the back of the deque
                - if EAT: remove the front of the deque
            - check if the front of the deque is expired (current day - front of the deque > X)
                - if expired, set expired flag to true and break the loop
        4. Print "yay!" if no cup of overnight oats expires
            - print "ono.." if at least one cup becomes too old

*/

#include <iostream>
#include "refrigerator.hpp"
using namespace std;

int main()
{
    int N, X;
    // FIXME: create a refrigerator object dynamically (using pointer) and set the shelf life
    cin >> N >> X;
    // FIXME: update the shelf life of the refrigerator object
    bool expired = false; // Flag to track if any cup of oats has expired
    for (DAY day = 0; day < N; day++)
    {
        string action;
        cin >> action;
        if (action == "ADD")
        {
            // FIXME: simulate the activity based on the action
        }
        else if (action == "EAT")
        {
            // FIXME: simulate the activity based on the action
            // break the loop if the eat action fails (oats are expired or no oats to eat)
        }
    }
    if (expired)
        cout << "ono.." << endl; // At least one cup of oats expired
    else
        cout << "yay!" << endl; // No cups of oats expired
    // FIXME: deallocate the refrigerator object if it was created dynamically
    return 0;
}