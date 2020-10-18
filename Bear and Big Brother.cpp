#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int a,b,ans=0;
    cin>>a>>b;
    while(a<=b){
        a = 3*a;
        b = 2*b;
        ans++;
    }
    cout<<ans;
    return 0;
}
