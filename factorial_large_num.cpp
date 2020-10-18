
//this code gives you the factorial of large number like any number greater than or equal to 100 we could not find factorial of big numbers using general factorial method


#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define mx 500

int perform(int res[],int size,int x)
{
	int carry=0,i,j,pro;
	for(i=0;i<size;i++)
	{
		pro=res[i]*x+carry;
		res[i]=pro%10;
		carry=pro/10;
	}
	while(carry)
	{
		res[size]=carry%10;
		size++;
		carry/=10;
	}
	return size;
}


void factorial(int n)
{
	int res[mx],i,j;
	res[0]=1;
	int res_l=1;
	for(i=2;i<=n;i++)
	res_l=perform(res,res_l,i);

	for(i=res_l-1;i>=0;i--)
	cout<<res[i];
}


int main()
{
	int n;
	cout<<"Give me a number: ";
	cin>>n;
	factorial(n);
	return 0;
}
