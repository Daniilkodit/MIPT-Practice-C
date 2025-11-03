#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
/*
Число 2520 является наименьшим числом, которое делится без остатка на числа от 2 до 10
Задача состоит в том, чтобы найти наименьшее число, которое делится без остатка на числа от 2 до N
Посылка должна состоять из программы, считывающей со стандартного ввода число N и
выводящей на стандартный вывод наименьшее общее кратное чисел от 2 до N включительно
Используйте тот факт, что lcm(a, b) == a * b / gcd(a, b)
*/
long long Lcm(int N);
long long Abs(long long x);
long long Mod (long long x, long long y);
long long Gcd(long long x,long long y);
int main(void)
{
    int N;
    if(scanf("%d",&N)!=1) abort();
    printf("%lld\n",Lcm(N));
    return 0;
}
long long Lcm(int N)
{
    long long i;
    long long a = 1;
    for(i=2;i<=N;i++)
    {
        a = (i*a)/Gcd(a,i);
    }
    return a;
}
long long Gcd (long long x, long long y)
{
    long long tmp;
    assert(y!=0);
    for(;y!=0;)
    {
        tmp = x;
        x = y;
        y = Mod(tmp,y);
    }
    return x;
}
long long Abs(long long x) { return x>0 ? x:-x;}
long long Mod (long long x, long long y)
{
    assert(y!=0);
    long long res;
    res = x%y;
    if(res<0) res+=Abs(y); // если вспомнить кольцо целых чисел по модулю "y" сразу все понятно
    return res;
}