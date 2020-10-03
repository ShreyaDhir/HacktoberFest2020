Programiz

Search Programiz
C++ Program to Check Armstrong Number
C++ Program to Check Armstrong Number
In this example, you will learn to check whether a number entered by the user is an Armstrong number or not.

To understand this example, you should have the knowledge of the following C++ programming topics:

C++ if, if...else and Nested if...else
C++ while and do...while Loop
A positive integer is called an Armstrong number (of order n) if

abcd... = an + bn + cn + dn + ...
In the case of an Armstrong number of 3 digits, the sum of cubes of each digit is equal to the number itself. For example, 153 is an Armstrong number because

153 = 1*1*1 + 5*5*5 + 3*3*3 
Example: Check Armstrong Number of 3 Digits
#include <iostream>
using namespace std;

int main() {
    int num, originalNum, remainder, result = 0;
    cout << "Enter a three-digit integer: ";
    cin >> num;
    originalNum = num;

    while (originalNum != 0) {
        // remainder contains the last digit
        remainder = originalNum % 10;
        
        result += remainder * remainder * remainder;
        
        // removing last digit from the orignal number
        originalNum /= 10;
    }

    if (result == num)
        cout << num << " is an Armstrong number.";
    else
        cout << num << " is not an Armstrong number.";

    return 0;
}
Output

Enter a positive integer: 371
371 is an Armstrong number.
In the program, we iterate through the while loop until originalNum is 0.

In each iteration of the loop, the cube of the last digit of orignalNum is added to result.

remainder = originalNum % 10;        
result += remainder * remainder * remainder;

And, the last digit is removed from the orignalNum.

When the loop ends, the sum of the individual digit's cube is stored in result.

Example: Check Armstrong Number of n Digits
#include <cmath>
#include <iostream>

using namespace std;

int main() {
   int num, originalNum, remainder, n = 0, result = 0, power;
   cout << "Enter an integer: ";
   cin >> num;

   originalNum = num;

   while (originalNum != 0) {
      originalNum /= 10;
      ++n;
   }
   originalNum = num;

   while (originalNum != 0) {
      remainder = originalNum % 10;

      // pow() returns a double value
      // round() returns the equivalent int
      power = round(pow(remainder, n));
      result += power;
      originalNum /= 10;
   }

   if (result == num)
      cout << num << " is an Armstrong number.";
   else
      cout << num << " is not an Armstrong number.";
   return 0;
}
