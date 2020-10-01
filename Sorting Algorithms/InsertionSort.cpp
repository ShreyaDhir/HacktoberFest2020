#include<iostream>
using namespace std;

void InsertionSort(int arr[],int n)
{
    int i,j,x;
    
    for(int i=1;i<n;i++)
    {
        x = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}


int main()
{
    int array[6] = {5, 1, 6, 2, 4, 3};
    int n=6;
    InsertionSort(array,6);
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"->"<<array[i];
    }
}