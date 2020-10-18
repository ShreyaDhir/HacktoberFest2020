#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int a, ans=1;
    cin>>a;
    while(a > 5){
        a = a - 5;
        ans++;
    }
    cout<<ans;
    return 0;
}
