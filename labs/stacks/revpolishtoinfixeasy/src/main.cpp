/*
Kattis problem - Reverse Polish Notation to Infix
STL - Stack
Updated By: FIXME
CSCI 111
Date: FIXME
Read and solve Reverse Polish Notation to Infix: https://open.kattis.com/problems/revpolishtoinfixeasy
Algorithm Steps:
    1. Read the input expression in Reverse Polish Notation (RPN) format.
    2. Use a stack to convert the RPN expression to infix notation.
    3. For each token in the RPN expression:
        - If the token is an operand (number), push it onto the stack.
        - If the token is an operator (+, -, *, /):
            - Pop the top two operands from the stack.
            - Combine them into a new infix expression with parentheses around it.
            - Push the new infix expression back onto the stack.
    4. After processing all tokens, the stack will contain one element, which is the final infix expression.
    5. Print the resulting infix expression.
*/
#include <iostream>
#include <stack>
#include <string>
#include "infix.hpp"

using namespace std;

int main()
{
    // Disable synchronization with C I/O for faster input/output
    ios::sync_with_stdio(false);
    cin.tie(nullptr); // Untie cin from cout for faster input

    string token;
    // FIXME - Create an instance of InfixConverter using pointer to dynamically allocate it
    while (cin >> token)
    {
        // FIXME: Process each token using the InfixConverter
    }
    // The stack will contain one element, which is the final infix expression
    // FIXME - Get the resulting infix expression from the converter and print it
    // FIXME - Deallocate the InfixConverter object if it was created dynamically
    return 0;
}