#include<stdio.h>
void main()
{
    int n,i,a[50],key,find=0;
    printf("enter n value");
    scanf("%d",&n);
    printf("enter %d elements",n);
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    printf("enter key element");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(key==a[i])
        {
            printf("element found at %d position",i);
            find=1;
            break;
        }
    }
    if(find==0)
      printf("element not found");
 }
