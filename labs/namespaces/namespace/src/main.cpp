/*
Namespaces and Enum Type Lab

Updated by: [Your Name]
Date: [Today's Date]
Instructor: [Instructor's Name]
CS1 - Foundations of Computer Science

Program demonstrates the use of preprocessor directive, namespace and enum type.
*/

#include <cstdio>
#include <iostream>
#include "../includes/utils.h"

using namespace std;

int main(int argc, char *argv[])
{
    char input;
    big_int num1;
    big_int num2;
    large_int sum;
    large_int prod;

    OPERATION oper;
    clear();
    do
    {
        show_menu();
        cin >> input;
        oper = get_operation(input);
        switch (oper)
        {
        case ADD:
            cout << "Enter two whole numbers separated by space: ";
            cin >> num1 >> num2;
            sum = my_functions::find_sum(num1, num2);
            printf("%lld + %lld = %lld\n", num1, num2, sum);
            break;
        case MULTIPLY:
            cout << "Enter two whole numbers separated by space: ";
            cin >> num1 >> num2;
            prod = my_functions::find_product(num1, num2);
            printf("%lld * %lld = %lld\n", num1, num2, prod);
            break;
            // FIXME1: complete the rest of the cases to perform other operations defined in enum type
        }
    } while (oper != QUIT);

    cin.ignore(1000, '\n');
    cout << "Good bye! Enter to exit the program...";
    cin.get();
    return 0;
}
