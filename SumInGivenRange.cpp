#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int t[4*100000];
void build(int a[],int v,int tl, int tr)
{
	if(tl==tr)
	{
		t[v]=a[tl];
	}
	else
	{
		int mid= (tl+tr)/2;
		build(a,v*2,tl,mid);build(a,v*2+1,mid+1,tr);
		
		// condition goes here say we want sum
		t[v]=t[v*2]+t[v*2+1];
	}
}
int sum(int v,int tl,int tr,int l, int r)// l,r -> real constraints for answer
{
	if(l>r)
	{
		return 0;
	}
	if(l==tl && r==tr)
	{
			return t[v];
	}
	int tm=(tl+tr)/2;
	return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}
void update(int v,int tl,int tr,int pos,int value)
{
	if(tl==tr)
	{
		t[v]=value;
	}
	else
	{
		int tm=(tl+tr)/2;
		if(pos<=tm)
		{
			update(2*v,tl,tm,pos,value);
		}
		else
		{
			update(2*v+1,tm+1,tr,pos,value);
		}
		t[v]=t[2*v]+t[2*v+1];
	}
	
}

int main()
{
	int n;
	cout<<"size of array <100000:";
	cin>>n;
	int a[n];
	int l,r;
	for(int i=0;i<n;i++)cin>>a[i];
	cin>>l>>r;
	build(a,1,0,n-1);
	cout<<sum(1,0,n-1,l,r);
}
