#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i,n,arr_max;
	int *arr,*backet;
	if(scanf("%d",&n)!=1) abort();
	arr = malloc(n*sizeof(int));
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
	arr_max = arr[i];
	for(i = 1; i<n;i++)
	{
		if(arr_max < a[i]) arr_max = a[i];
	}
	backet = calloc(arr_max+1,sizeof(int));
	for(i =0 ;i<n;i++)
	{
		backet[arr[i]]++;
	}
	for(i=0;i<arr_max+1;i++)
	{
		printf("%d ",backet[i]);
	}
	printf("\n");

}
