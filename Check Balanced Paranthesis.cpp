#include <bits/stdc++.h>
using namespace std;

#define ll long long

string isBalanced(string str)
{
    stack<char> st;
    for (auto c : str)
    {
        switch (c)
        {
        case '{':
        case '[':
        case '(':
            st.push(c);
            break;
        case '}':
            if (st.empty() || st.top() != '{')
            {
                return "Not Balanced";
            }
            st.pop();
            break;
        case ']':
            if (st.empty() || st.top() != '[')
            {
                return "Not Balanced";
            }
            st.pop();
            break;
        case ')':
            if (st.empty() || st.top() != '(')
            {
                return "Not Balanced";
            }
            st.pop();
            break;
        }
    }
    return (st.empty() ? "Balanced" : "Not Balanced");
}

int main()
{

    string s;
    cin >> s;
    cout << isBalanced(s) << endl;
    return 0;
}
