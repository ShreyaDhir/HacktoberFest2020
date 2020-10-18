#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    while(b != 0){
        if(a%10 == 0){
            a = a/10;
            b--;
        }
        else{
            a = a-1;
            b--;
        }
    }
    cout<<a;
    return 0;
}
