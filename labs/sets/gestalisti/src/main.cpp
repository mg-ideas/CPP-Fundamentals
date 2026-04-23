/*
Kattis - Gestalisti
Read Problem Description: https://open.kattis.com/problems/gestalisti

Updated by: [Your Name]
Date: [Date]

Algorithm Steps:
1. Read number of commands
3. Create unordered set to store the names of the guests in a struct/class called Guests
3. For each command, read the command and the name of the guest
    i. If the command is "+", add the guest to the set of guests
    ii. If the command is "-", remove the guest from the set of guests
    iii. If the command is "?", check if the guest is in the set of guests and print "Jebb" or "Neibb" accordingly

*/

#include <iostream>
#include "guests.hpp"

int main()
{
    ios::sync_with_stdio(false); // Disable synchronization with C I/O for faster input/output
    cin.tie(nullptr);            // Untie cin from cout to allow independent flushing of output

    int n;
    cin >> n;
    cerr << "FIXME - Use a pointer to the Guests class/struct and dynamically allocate memory for it!" << endl;

    for (int i = 0; i < n; ++i)
    {
        char command;
        string name;
        cin >> command >> name;

        if (command == '+')
        {
            cerr << "FIXME - Add the guest to the set of guests using the right method!" << endl;
        }
        else if (command == '-')
        {
            cerr << "FIXME - Remove the guest from the set of guests using the right method!" << endl;
        }
        else if (command == '?')
        {
            cerr << "FIXME - Check if the guest is in the set of guests and print the right output!" << endl;
        }
    }
    return 0;
}
