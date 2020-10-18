#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int ans = 0;
    char ch[1000];
    cin>>ch;

    for(int i = 0; ch[i] !='\0'; i++){
        if(ch[i] == '7' || ch[i] == '4'){
            ans++;
        }
    }
    if(ans == 7 || ans == 4){
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}
