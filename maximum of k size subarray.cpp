#include<bits/stdc++.h>
using namespace std;

void subarr(int a[], int n, int k)
{
	int max=0;
	for(int i=0;i<=n-k;i++)
	{
		max=a[i];
		for(int j=1;j<k;j++)
		{
			if(max<a[i+j])
			max=a[i+j];
		}
		cout<<max<<" ";
	}
	
}
int main()
{
	int a[]={1,6,5,8,9,2};
	int n=sizeof(a)/sizeof(a[0]);
	int k;
	cin>>k;
	subarr(a,n,k);
}
