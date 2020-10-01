#include<iostream>
#include<vector>
using namespace std;

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void BubbleSort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main()
{
    int arr[] = {5, 6, 2, 6, 9, 0, -1};
    int n = 7;
    
    BubbleSort(arr,n);
    
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<n;i++)
        cout<<"->"<<arr[i];
}