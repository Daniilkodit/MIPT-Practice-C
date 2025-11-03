#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
/*
На стандартном вводе дано число n.
Вам надо вывести на стандартный вывод количество простых чисел меньших или равных n.
*/
int Count_prime(unsigned int);
int main(void)
{
    unsigned int n;
    if(scanf("%d",&n)!=1)
    {
        abort();
    }
    printf("%d\n",Count_prime(n));
    return 0;
    
}
int Count_prime(unsigned int n)
{
    char* mas_res = calloc(n+1,sizeof(char));
    int i = 2,j,count = 0;
    for(i = 2;i*i<n+1;i++)
    {
        for(j = i*i;j<n+1;j+=i) mas_res[j] = 1;
    }

    for(i = 2;i<n+1;i++)
    {
        if(mas_res[i]==0) count++;
    }
    return count;
}