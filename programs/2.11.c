#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int test_ferma(long long unsigned N);
unsigned long long pow_m (unsigned long long, unsigned long long,unsigned long long);
unsigned long long Gcd (unsigned long long, unsigned long long);
int main(void)
{
    unsigned long long  N;
    if(scanf("%llu",&N)!=1) abort();
    printf("%d\n",test_ferma(N));
    
}
unsigned long long Gcd (unsigned long long x, unsigned long long y)
{
    unsigned long long tmp;
    for(;y!=0;)
    {
        tmp = x;
        x = y;
        y = tmp%y;
    }
    return x;
}
unsigned long long pow_m (unsigned long long n, unsigned long long exp,unsigned long long m)
{
    unsigned long long  res = 1;
    while(exp>0)
    {
        if(exp%2==1) res = (res*n)%m;
        n = (n*n)%m;
        exp/=2;
    }
    return res;
}
int test_ferma(unsigned long long  N)
{
    unsigned long long  a,res =1;
    int i;
    if(N==1) return 0;
    srand(time(NULL));
    for(i = 0;i<20;i++)
    {
        a = 2 + (rand() % (N - 3));
        if(Gcd(a,N)!=1 && a<N) return 0;
        else continue; 
        res = pow_m(a,N-1,N);
        if(res!=1) return 0;
    }
    return 1;
}