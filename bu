#include<iostream.h>
#include<conio.h>
void main()
{
 int a[50],n,i,j,tmp;
 clrscr();
 cout<<"Enter the size of array=";
 cin>>n;
 cout<<"Enter array elements=";
  for(i=0;i<n;i++)
    {
     cin>>a[i];
    }
 for(i=0;i<n;i++)
   for( j=0;j<n;j++)
     {
       if(a[j]>a[j+1])
	 {
	  tmp=a[j];
	  a[j]=a[j+1];
	  a[j+1]=tmp;
	 }
     }
	 cout<<"sorted array is=";
	    for(i=0;i<n;i++)
	     {
	      cout<<"\n"<<a[i];
	     }
 getch();
}
