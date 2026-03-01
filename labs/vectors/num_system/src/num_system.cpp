#include <string>
#include <cmath>
#include <vector>
#include <cctype>
#include <iostream>
#include "../includes/num_system.hpp"

using namespace std;

string decToBin(ull num)
{
    // FIXME3 - implement algorithm step in Ch03-StdInputOutput chapter
    // or use hint from decToOct function
    return to_string(num);
}

ull binToDec(string binaryNumber)
{
    // FIXME4 - implement algorithm described in Ch03-StdInputOutput chapter
    // or use hints from binToOct function
    return 0;
}

string decToOct(ull num)
{
    /*
    Algorithm steps:
    1. repeteadly divide the decimal number by base 8 until the quotient becomes 0
    2. collect the remainder for each division
    3. reverse the order of the remainders
        - the first remainder is the last digit in octal
    */
    vector<int> octal;
    int divisor = 8; // base 8
    ull quotient = num;
    int remainder;
    // step 1 and 2
    cout << "quotient = " << quotient << endl;
    while (quotient != 0)
    {
        remainder = quotient % divisor;
        quotient = quotient / divisor;
        octal.push_back(remainder);
        // debug log
        cerr << "quotient = " << quotient << " " << remainder << endl;
    }

    // step 3. convert octal vector into string for easy printing the result
    // collect remainders in reverse order
    string ans = "";
    while (not octal.empty())
    {
        // collect from the last element
        ans += to_string(octal.back());
        // remove the last element
        octal.pop_back();
    }
    return ans;
}

ull octToDec(string octalNumber)
{
    /* Algorithm steps:
    1. multiply each octal digit by its place value in octal
    2. sum all place values
    e.g. (173) base 8 = 1x8^2 + 7x8^1 + 3x8^0 = 64+56+3 = (123) base 10
    */
    ull ans = 0;
    int exp;
    // traverse from last digit to the first digit of octal number
    for (int i = octalNumber.size() - 1; i >= 0; i--)
    {
        exp = octalNumber.size() - 1 - i;
        int digit = int(octalNumber[i]) - int('0');
        // step 1 and 2
        ans += digit * pow(8, exp);
    }
    return ans;
}

int menuOption()
{
    int choice;
    cout << "Menu options: \n"
         << "1. Convert Decimal to Binary Number System\n"
         << "2. Convert Binary to Decimal Number System\n"
         << "3. Convert Decimal to Octal Number System\n"
         << "4. Convert Octal to Decimal Number System\n"
         << "5. Exit the program\n";
    cout << "Enter your choice: [1-5]: ";
    cin >> choice;
    return choice;
}