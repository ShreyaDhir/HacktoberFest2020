#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int num1, num2, result;
    char op;

    cout << "enter first number: ";
    cin >> num1;
    cout << "enter 2nd number: ";
    cin >> num2;
    cout << "enter operator(+,-,*,/): ";
    cin >> op;

    if (op == '+')
    {
        result = num1 + num2;

    }
    else if (op == '-')
    {
        result = num1 - num2;
    }
    else if (op == '/')
    {
        result = num1 / num2;
    }
    else if (op == '*')
    {
        result = num1 * num2;

    }
    else
    {
        cout << "invalid operator";
    }

    cout << result;
    return 0;
}

