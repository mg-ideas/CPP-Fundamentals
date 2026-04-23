#pragma once
#include <string>
#include <stack>

using namespace std;

struct InfixConverter
{
    stack<string> stk; // Stack to hold operands and intermediate infix expressions
    void process_token(const string &token);
    string get_infix_expression();
};