#include<stdio.h>
#include<stdlib.h>
int main()
{
	int sum,n;
	int* arr,*nominal;
	int cnt, ind;
	scanf("%d%d",&sum,&n);
	arr = (int*)calloc(sizeof(int),(sum+1));
	nominal = (int*)malloc(sizeof(int)*n);
	for(int i = 0;i<n && scanf("%d",&nominal[i])==1;i++){} 
	for(int i=1;i<sum+1;i++)
	{
		cnt = sum+1;
		for(int j = 0;j<n;j++)
		{
			ind = i-nominal[j];
			if(ind==0) {arr[i] = 1;cnt = sum+1; break;}
		       	else if(ind > 0 && cnt>arr[ind] && arr[ind]!=0)cnt = arr[ind];	
		}
		if(cnt!=sum+1) arr[i] = cnt+1;
	}
	printf("%d\n",arr[sum]);

}
