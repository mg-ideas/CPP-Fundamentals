/*
Author: <FIXME: your name here>
Course: CSCI111
Semester: <FIXME: semester here>

Algorithm steps:
1. program will prompt user to enter some text until user wants to stop
2. program will check if the text has email address and social security number in it using regular expressions
3. to check if the text has email address, social security number and a valid credit card number in it.
    - we can use the following regular expressions
    a. email address - [a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}
    b. social security number - \d{3}-\d{2}-\d{4}
    c. FIXME - add regular expression for credit card number
*/

#include <iostream>
#include <string> //library for string data type
#include "../includes/util.hpp"

using namespace std;

// main function that can take some command line arguments
int main(int argc, char *argv[])
{
    string *text = nullptr; // variable to store user input
    text = new string;
    string *ssn = new string;
    string *email = new string;
    // FIXME - add a dynamic variable to store credit card number
    bool keepRunning = false; // variable to control the while loop
    do                        // while keepRunning equals to true
    {
        // prompt user to enter some text
        cout << "Please enter word/phrase to check whether it contains SSN or email:\n";
        // use getline to read data from common input and store into text variable
        getline(cin, *text, '\n'); // read until the end of line character is found

        *email = util::find_email(*text);
        // pointer objects can access member functions using -> operator, so we can also write it as email->empty() instead of (*email).empty()
        if (email->empty())
            cout << "Email not found in " << text << endl;
        else
            cout << "Email found: " << *email << endl;

        // FIXME: find social security number and credit card number in the same input text and print the results as well
        // FIXME5: add code to find credit card number in the same input text and print the result as well

        cout << "Would you like to test another phrase? [yes/no]: " << endl;
        cin >> *text;           // read in the answer
        cin.ignore(1000, '\n'); // ignore the newline character left behind
        string *answer = new string;
        for (int i = 0; i < text->length(); i++)
            // converts uppercase letter to lower and concatenates it to answer variable
            *answer += char(tolower(text->at(i)));

        if ((*answer == "y" || *answer == "yes"))
            keepRunning = true;
        else
            keepRunning = false;

    } while (keepRunning);
    cout << "Good bye...\n";
    delete text; // FIXME free the memory allocated for input variable
    // FIXME free all the dynamically allocated memory for other variables as well
    return 0;
}
