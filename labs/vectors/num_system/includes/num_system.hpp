#pragma once
#include <string>
using namespace std;

using ull = unsigned long long int;

// System specific macro function clear_screen that
// clears console text
// NOTE: system call is not security best practice!
#ifdef _WIN32
#define clear_screen() system("cls") // not secure!
#else
#define clear_screen() system("clear") // not secure!
#endif

// converts decimal number to binary representation
string decToBin(ull);

// converts binary number to decimal representation
ull binToDec(string binaryNum);

// converts decimal number to octal representation
string decToOct(ull);

// converts octal number to decimal number
ull octToDec(string octalNum);

// function to display and capture menu options
int menuOption();