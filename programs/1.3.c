#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
Даны два целых числа x и y
Необходимо найти их наибольший общий делитель d и целые, возможно отрицательные числа a и b, такие, что:
ax + by = d
Используйте тип long long для всех чисел
Посылка должна состоять из программы,
считывающей со стандартного ввода два числа x и y и выводящей на стандартный вывод три числа: a, b, d
*/
/*
Идея
Поддереживаю a,a',b,b': a'm + b'n = c; am+ bn = d; c = n,d = m; потом с = d, d = c%d;
*/
void Ob_E(long long x, long long y);
long long Abs(long long x);
long long Mod(long long x,long long y);
int main(void)
{
    long long x,y;
    int res;
    res  = scanf("%lld%lld",&x,&y);
    if(res != 2 || y==0)
    {
        printf("Error\n");
        abort();
    }
    Ob_E(x,y);
}
void Ob_E(long long x, long long y)
{
    long long a1 = 0,b1 =1 ,a2 = 1,b2 = 0;
    long long d = y, c = x, q,r,swap;
    q = c/d;
    r = Mod(c,d);
    if(c == (q-1)*d +r) q--;
    else if(c == (q+1)*d +r)q++;


    for(;r!=0;)
    {
        c = d; // алг евклида
        d = r;
        // обобщенный дальше
        swap = a2;
        a2 = a1;
        a1 = swap - q*a1;
        swap = b2;
        b2 = b1;
        b1 = swap - q*b1;
        r = Mod(c,d);
        q  = c/d;
        if(c == (q-1)*d +r) q--;
        else if(c == (q+1)*d +r)q++;    
    }
    printf("%d %d %d\n",a1,b1,d);

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