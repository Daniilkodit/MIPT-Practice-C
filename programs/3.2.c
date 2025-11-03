#include <stdio.h>
#include <stdlib.h>
int myrand() {
  static unsigned long int seed = 1;
  seed = seed * 1103515245 + 12345;
  return (unsigned int)(seed / 65536) % 32768;
}

int main()
{
	int N,i=0,swap,j;
	int* mas;
	if(scanf("%d",&N)!=1) abort();
	if(N==0) {printf("0\n"); return 0;}
	mas = malloc(N*sizeof(int));
	for(i=0;i<N && scanf("%d",&mas[i]);i++);
	for(i = N-1;i>=0;i--)
	{
		j = myrand()%(i+1);
		swap = mas[j];
		mas[j] = mas[i];
		mas[i] = swap;
	}
	for(i=0;i<N;i++) printf("%d ",mas[i]);
	printf("\n");
}

