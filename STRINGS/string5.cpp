#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    for(int i=0;i<250;i++)
    {
        char ch=i;
        cout<<i<<" "<<ch<<" , ";
        if(i%10==0) cout<<endl;
    }


    return 0;
}
