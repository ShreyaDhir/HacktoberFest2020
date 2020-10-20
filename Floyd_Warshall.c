//C program for Floyd-Warshall Algorithm.
#include<stdio.h>

int main()
{
	int n;
	printf("Enter n:");
	scanf("%d", &n);
	
	int A[n][n];
	printf("Enter cost adjacency matrix:\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			scanf("%d", &A[i][j]);
			if(A[i][j]==0)
				A[i][j]=999;
		}
	int i, j, k;		
	for(k=0; k<n; k++)
	{
		for(i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
			if(i==j)
				continue;
			if(A[i][j]>(A[i][k]+A[k][j]))
				A[i][j]=A[i][k]+A[k][j];
			}
		}
	}
	
	for(i=0; i <n; i++)
		A[i][i]=0;
		
	printf("\n\nAll Pair Shortest Path Matrix:\n");
	
	for(i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}
