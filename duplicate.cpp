#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *nums = new int[n];
    for(int i = 0; i < n; ++i)
        cin>>nums[i];
    for(int i = 0; i < n; ++i)
    {
        if(abs(nums[i]) == n)
            continue;
        if(nums[abs(nums[i])] < 0)
            cout<<abs(nums[i])<<' ';
        else
            nums[abs(nums[i])] *= -1;
    }
    delete [] nums;
}