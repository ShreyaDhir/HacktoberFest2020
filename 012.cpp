#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i)
        cin>>arr[i];
    int zero = 0, one = 1, two = n-1;
    while(one <= two)
    {
        if(arr[one] == 1)
            one++;
        else if(arr[one] == 2)
            swap(arr[one], arr[two--]);
        else if(arr[one] == 0)
            swap(arr[one], arr[zero++]);
    }
    for(int i = 0; i < n; ++i)
        cout<<arr[i]<<' ';
    delete [] arr;
}