#include<stdio.h>
#include<stdlib.h>
#define Max(a,b) a>b ? a:b
int main()
{
	int ves,n;
	int**arr;
	int*things;
	scanf("%d%d",&ves,&n);
	things = malloc(sizeof(int)*(n+1));
	arr = (int**)malloc(sizeof(int*)*(n+1));
	arr[0] = (int*)calloc(sizeof(int),ves+1);
	for(int i = 1;i<n+1;i++)
	{

		arr[i] = (int*)calloc(sizeof(int),ves+1);
		scanf("%d",&things[i]);
	}
	for(int i =1;i<n+1;i++)
	{
		for(int j =1;j<ves+1;j++)
		{
			if(j-things[i]>=0)arr[i][j] = Max((arr[i-1][j-things[i]]+1),arr[i-1][j]);
			else arr[i][j] = arr[i-1][j];
		}
	}
	printf("%d\n",arr[n][ves]);
}
