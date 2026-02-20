/*
Author: <FIXME: your name here>
Course: CSCI111
Semester: <FIXME: semester here>

Algorithm steps:
    1. program will prompt user to enter some text until user wants to stop
    2. program will check if the text is a palindrome or not and print the result
    3. to check if the text is a palindrome, we can use one of following two algorithms
        a. naive algorithm - palindrome::naive:
            i. don't ignore non-alphanumeric characters
            ii. reverse the text and compare it with the original text, if they are the same then it is a palindrome otherwise it is not
        b. optimized algorithm - palindrome::optimized:
            i. ignore all non-alphanumeric characters
            ii. using two indices, compare the first and last alphanumeric character of the text, then move inward until the middle index is reached
            iii. if all the characters are the same then it is a palindrome
            iv. if any character is different then it is not a palindrome, and we can stop checking further
*/

#include <iostream>
#include <string> //library for string data type
#include <cctype> //provides functions for char data type
#include "../includes/palindrome.hpp"

using namespace std;

// main function that can take some command line arguments
int main(int argc, char *argv[])
{
    string *input = nullptr; // variable to store user input
    input = new string;

    bool palin = false;
    bool keepRunning = false; // variable to control the while loop
    do                        // while keepRunning equals to true
    {
        // prompt user to enter some text
        cout << "Please enter word/phrase to check whether or not it is a palindrome:\n";
        // use getline to read data from common input and store into text variable
        getline(cin, *input, '\n'); // read until the end of line character is found

        // FXIME5: change isPalindrome to isPalindrome1 once the function is fixed
        palin = palindrome::naive(*input);
        // FIXME print the data instead of memory address of input variable
        cout << "Naive algorithm says: " << input << " is ";

        if (palin == true)
            cout << "a palindrome." << endl;
        else
            cout << "NOT a palindrome." << endl;

        palin = palindrome::optimized(*input);
        cout << "Optimized algorithm says: " << input << " is ";
        if (palin == true)
            cout << "a palindrome." << endl;
        else
            cout << "NOT a palindrome." << endl
                 << endl;

        cout << "Would you like to test another phrase? [yes/no]: " << endl;
        cin >> *input;          // read in the answer
        cin.ignore(1000, '\n'); // ignore the newline character left behind
        string *answer = new string;
        for (int i = 0; i < (*input).length(); i++)
            // converts uppercase letter to lower and concatenates it to answer variable
            *answer += char(tolower((*input).at(i)));

        if ((*answer == "y" || *answer == "yes"))
            keepRunning = true;
        else
            keepRunning = false;

    } while (keepRunning);
    cout << "Good bye...\n";
    delete input; // FIXME free the memory allocated for input variable
    return 0;
}
