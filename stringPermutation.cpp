

#include <bits/stdc++.h>
#include <string>
using namespace std;

vector<string> permute(string s, int l, int r, vector<string> &pms)
{

    if (l == r)
        pms.push_back(s);

    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]);
            permute(s, l + 1, r, pms);
            swap(s[l], s[i]);
        }
    }

    return pms;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string s;
        cin>>s;
        vector<string> pms, v;
        v = permute(s, 0, s.length() - 1, pms);
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
            cout << v[i]<<" ";
            cout<<endl;
    }

    return 0;
}