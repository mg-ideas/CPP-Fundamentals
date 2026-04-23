#include "infix.hpp"

void InfixConverter::process_token(const string &token)
{
    if (token == "+" || token == "-" /* FIXME: add other operators */)
    {
        // Pop the top two operands from the stack
        string operand2 = stk.top();
        stk.pop();
        string operand1 = stk.top();
        // FIXME - Pop the top operand from the stack and store it in operand1
        // Combine them into a new infix expression with parentheses
        // FIXME - Combine operand1 operator operand2 into a new infix expression with parentheses around it
        // Push the new infix expression back onto the stack
        // FIXME - Push the new infix expression back onto the stack
    }
    else
    {
        // Token is an operand (number), push it onto the stack
        stk.push(token);
    }
}

string InfixConverter::get_infix_expression()
{
    // The stack will contain one element, which is the final infix expression
    string infixExpr = stk.top(); // Get the resulting infix expression
    stk.pop();                    // Pop the infix expression from the stack
    return infixExpr;             // Return the infix expression
}