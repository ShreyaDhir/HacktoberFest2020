#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int k,n,w,t = 0;
    cin>>k>>n>>w;
    for(int i = 1; i <= w; i++){
        t = t + (i*k);
    }
    if(t-n < 0){
        cout<< 0;
        return 0;
    }
    cout<< t - n;
    return 0;
}
