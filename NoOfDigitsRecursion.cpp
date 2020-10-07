#include <iostream>
using namespace std;

int countDigits(int n)
{

    if (n == 0)
        return 0;

    return 1 + countDigits(n / 10);
}

int main(int argc, char const *argv[])
{
    cout << countDigits(123456);

    return 0;
}
