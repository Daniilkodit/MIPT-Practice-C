#include<stdio.h>
#include<stdlib.h>
void product(int*,int*,int*,int,int);
int main(void)
{
	int n1,n2,i,j;
	int* polinom1,*polinom2,*res;
	if(scanf("%d%d",&n1,&n2)!=2) abort();
	polinom1 = malloc(n1*sizeof(int));
	polinom2 = malloc(n2*sizeof(int));
	res = calloc((n1+n2),sizeof(int));
	for(i = 0;i<n1;i++) scanf("%d",&polinom1[i]);
	for(i = 0;i<n2;i++) scanf("%d",&polinom2[i]);
	product(polinom1,polinom2,res,n1,n2);
	j = n1+n2;
	for(i=0;i<n1+n2;i++)
	{
		if(res[i]==0)
		{
			j = i;
			while(i<n1+n2 && res[i] == 0) i++;
			if(i==n1+n2) break;
			j = n1+n2;
		}
	}
	for(i=0;i<j;i++) printf("%d ",res[i]);
}
void product(int* p1,int* p2,int* res,int n1,int n2)
{
	int i,j;
	for( i  = 0 ;i<n1;i++)
	{
		for(j = 0;j<n2;j++)
		{
			res[i+j] += p1[i]*p2[j];
		}
	}

}
