#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
Problem RL -- рекурсия в цикл
Ниже приведён исходный код программы для рекурсивного алгоритма Евклида.
Ваша задача: переписать его так, чтобы вместо рекурсии использовался цикл
Посылка должна состоять из программы,
считывающей со стандартного ввода два числа x и y и выводящей на стандартный вывод одно число g
*/
// https://godbolt.org/ тестировщик
int Abs(int x);
int Mod(int x,int y);
int Gcd(int x,int y);
int main(void)
{
    int x,y,res;
    //printf("VVedite x,y\n");
    res = scanf("%d%d",&x,&y);
    if(res != 2 || y == 0)
    {
        printf("Error\n");
        abort();
    }
    printf("%d\n",Gcd(x,y));
    return 0;
}
int Gcd (int x, int y)
{
    int tmp;
    assert(y!=0);
    for(;y!=0;)
    {
        tmp = x;
        x = y;
        y = Mod(tmp,y);
    }
    return x;
}
int Abs(int x) { return x>0 ? x:-x;}
int Mod (int x, int y)
{
    assert(y!=0);
    int res;
    res = x%y;
    if(res<0) res+=Abs(y); // если вспомнить кольцо целых чисел по модулю "y" сразу все понятно
    return res;
}