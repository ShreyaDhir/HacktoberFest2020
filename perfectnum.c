#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i=0,sum=0;
    for(i=1;i<n;i++)
    {
        if(n&i==0)
        sum+=i;
    }
    if(sum==n)
    {printf("%d is a Perfect Number",n);}
    else
    {
       printf("%d is not a Perfect Number",n);
    }
    
}
