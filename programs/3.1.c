#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned N;
	int i,a,amax,amin;
	if(scanf("%u",&N)!=1) abort();
	if(N==0) {printf("0 0\n");return 0;}
	scanf("%d",&amax);
	amin = amax;
	for(i = 1;i<N && scanf("%d",&a)==1;i++)
	{
		if(amax<a) amax = a;
		if(amin>a) amin = a;
	}
	printf("%d %d\n",amin,amax);
}
