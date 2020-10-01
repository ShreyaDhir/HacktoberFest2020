
#include<iostream>
#include<cstdlib>

using namespace std;


void swap(int *a, int *b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int a[],int start,int end)
{
    int pivot, index, i;
    index = start;
    pivot = end;
    
    for(i=start;i<end;i++ )
    {
        if(a[i] < a[pivot])
        {
            swap(&a[i], &a[index]);
            index++;
        }
    }
    swap(&a[pivot], &a[index]);
    return index;
}

int QuickSort(int a[],int start,int end)
{
    int pindex;
    if(start<end)
    {
        pindex = Partition(a,start,end);
        
        QuickSort(a, start, pindex-1);
        QuickSort(a, pindex+1, end);
    }
}

int main()
{
    int n,i;
    cout<<"Enter the number of data elements to be sorted"<<endl;
    cin>>n;
    cout<<"Enter the Elements"<<endl;
    
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    QuickSort(arr,0,n-1);
    cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        	cout<<"->"<<arr[i];
 
	return 0;
}