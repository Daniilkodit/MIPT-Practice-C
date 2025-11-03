#include<stdio.h>
#include<stdlib.h>

int moveright(int *arr, int key, int last) {
    int mid,left = 0, right = last;
    while (left <= right) {
        mid = (right + left) / 2;
        if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if(left>=last) left = last;
    for (int i = last; i > left; i--) {
        arr[i] = arr[i-1];
    }
    return left;
}
int main()
{
	int N,i,last;
	int * mas;
	scanf("%d",&N);
	mas = malloc(N*sizeof(int));
	for(i=0;i<N && scanf("%d",&mas[i])==1;i++);
	scanf("%d",&last);
	last = moveright(mas,mas[last],last);
	for(i=0;i<N;i++) printf("%d ",mas[i]);
	printf("\n%d\n",last);
	return 0;
}
