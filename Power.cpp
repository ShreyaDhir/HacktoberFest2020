// find power of a no

#include <iostream>

using namespace std;

int power(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return power(m, n - 1) * m;
}

int fasterPower(int m, int n)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
    {
        return power(m * m, n / 2);
    }
    return m * power(m * m, (n - 1) / 2);
}

int main()
{
    int n = 6, m = 2;

    cout << fasterPower(m, n);
    return 0;
}