#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
/*
Первым простым числом является 2, шестым является 13
Задача заключается в том, чтобы вычислить N-e простое число
Посылка должна состоять из программы, считывающей со стандартного ввода число N
и выводящей на стандартный вывод N-e простое
*/
unsigned long long int Num_prime(unsigned int);
int main(void)
{
    unsigned int n;
    if(scanf("%d",&n)!=1)
    {
        abort();
    }
    printf("%lld\n",Num_prime(n));
    return 0;
    
}
unsigned long long int Num_prime(unsigned int n)
{

    unsigned int N = n;
    char* mas_res = calloc(N,sizeof(char));
    unsigned long long int i = 2,j,count = 0;
    for(i = 2;i*i<N;i++)
    {
        for(j = i*i;j<N;j+=i) mas_res[j] = 1;
    }

    for(i = 2;i<N;i++)
    {
        if(mas_res[i]==0) {count+=i;}
    }
    return count;
}
