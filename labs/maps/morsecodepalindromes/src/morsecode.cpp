#include <iostream>
#include <string>
#include "morsecode.h"

using namespace std;

// solving the problem for kattis
void solve()
{
    string phrase, morse;
    // string is a phrase: with space, puncuation, lower and uppercase letters
    // FIXME1 - Algorithm step 2
    // read english phrase into phrase variable
    // FIXME2 - Algorithm step 3
    // convert phrase to morse code
    // FIXME3 - Algoritm step 4
    // check if morse code is a palindrome calling is_palindrome function
    // FIXME4 - Algorithm step 5
    // print 1 if it is a palindrome, 0 otherwise
}

// function definitions
string convert_to_morse(const string &phrase)
{
    string morse = "";
    // convert phrase to morse code
    // for each char in phrase, convert char to uppercase, find its morse code in morse_code map
    // append morse code to a string if char key is found
    for (char c : phrase)
    {
        c = char(toupper(c));
        // FIXME5 - find morse code for char c in morse_code map and append it to morse string
    }
    return morse;
}

bool is_palindrome(const string &morse)
{
    // FIXME6 - check if morse code is a palindrome
    // return true if it is a palindrome, false otherwise
    // Algorithm step:
    // compare first and last char
    // if they are the same, compare second and second last char
    // if they are the same, compare third and third last char
    // repeat until all chars are compared until mid index or a mismatch is found
    // NOTE: empty morse code is not a palindrome!
    return true;
}