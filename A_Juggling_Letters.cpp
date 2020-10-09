#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Earlier your program didn't use to ask for number's so here's my helping hand
    int t;
    cin >> t;
    while (t--)
    {
        cout<<"Enter a number please"<<endl;
        int n;
        cin >> n;
        int count[26] = {0};
        t--;

        for (int i = 0; i < n; i++)
        {
            cout<<"Enter a number please"<<endl;
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
