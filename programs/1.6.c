#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
Число может быть единственным образом представлено в факториальной системе счисления.
Пример: 463=3*5! + 4 * 4! + 1 * 3! + 0 * 2! + 1 * 1! = 34101
Правила довольно просты: у каждого n! может быть коэффициент 0 <= k <= n
Ваша задача написать программу которая принимает на вход положительное десятичное число
 и печатает его в факториальной системе счисления.
*/
void Fact_system(long long n);
int main(void)
{
    long long n;
    int res;
    res = scanf("%lld",&n);
    if(res!=1)
    {
        printf("Error\n");
        abort();
    }
    Fact_system(n);
    return 0;
}
void Fact_system(long long n)
{
    int i,j;
    long long fact = 1;
    long long N = n;
    long long mas[32] = {0};
    if(n == 0) {printf("0\n"); return;}
    for(i=2;fact<=n;i++)
    {
        fact*= i;
        mas[i-2] = (N%fact)/(fact/i);
        N-= (fact/i)*mas[i-2];
        //printf("%lld %lld %lld\n", N,mas[i-2],fact);
        
    }
    j = i-3;
    for(j;j>=0;j--)
    {
        printf("%lld.", mas[j]);
    } 
    printf("\n");
}