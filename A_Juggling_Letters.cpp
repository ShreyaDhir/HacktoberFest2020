#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int count[26] = {0};

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (char ch : s)
            {
                count[ch - 'a']++;
            }
        }
        bool ans = true;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] % n != 0)
            {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}