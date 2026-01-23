/*
Program prompts user to enter two numbers.
It then sums and displays the results using a function.
*/
#include <iostream>

using namespace std;

float sum_two(float a, float b)
{
    float total = a + b;
    return total;
}

int main()
{
    float num1, num2;
    cout << "Enter two numbers separated by space: ";
    cin >> num1 >> num2;
    float sum = sum_two(num1, num2);
    cout << "The sum of " << num1 << " and " << num2 << " = " << sum << endl;
    return 0;
}