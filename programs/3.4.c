#include<stdio.h>
#include<stdlib.h>

void moveright(int *arr, int N, int last) {
	int swap,i,ind_min = last;
	for(i=last+1;i<N;i++)
	{
		if(arr[ind_min]>arr[i]) ind_min = i;
	}
	swap = arr[ind_min];
	arr[ind_min] = arr[last];
	arr[last] = swap;
	
}
int main()
{
        int N,i,last;
        int * mas;
        if(scanf("%d",&N)!=1) abort();
        mas = malloc(N*sizeof(int));
        for(i=0;i<N && scanf("%d",&mas[i])==1;i++);
        scanf("%d",&last);
        moveright(mas,N,last);
        for(i=0;i<N;i++) printf("%d ",mas[i]);
        printf("\n");
        return 0;
}
