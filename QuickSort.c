
    int i = (l - 1);  



    for (int j = l; j <= h- 1; j++) 

    { 



        if (arr[j] < pivot) 

        { 

            i++;    

            swap(&arr[i], &arr[j]); 

        } 

    } swap(&arr[i + 1], &arr[h]); 

    return (i + 1); 
} 




void quickSort(int arr[], int l, int h) 
{ 

    if (l < h) 

    { 



        int k = split(arr, l, h);

        quickSort(arr, l, k- 1); 

        quickSort(arr, k+ 1, h); 

    } 
} 
int main()

{

int a[50],n,i;

scanf("%d",&n);

for(i=0;i<n;i++) 

     scanf("%d",&a[i]);

quickSort(a,0,n-1)  ;

printf("Sorted array is :");

for(i=0;i<n;i++)

     printf("%d ",a[i]);

return 0;
}
