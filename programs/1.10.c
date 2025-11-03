#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
Дано положительное число x, не больше чем 2^31-1 (обычный int на большинстве систем)
Необходимо найти его единственное представление суммой чисел Фибоначчи
если запретить в представлении две единицы рядом
Посылка должна состоять из программы,
считывающей со стандартного ввода число x и выводящей на стандартный вывод единицы и нули без пробелов
Единица в позиции n означает, что fib(n) входит в сумму
*/
void Fib_system(unsigned x);
int main(void)
{
    unsigned x;
    int res;
    res = scanf("%u",&x);
    if(res!=1)
    {
        abort();
    }
    Fib_system(x);
}
void Fib_system(unsigned x)
{
    unsigned long x1 = 0, x2 = 1, swap;
    int flag = 1;
    if (x==1){printf("1\n");return;}
    if(x==0){printf("0\n"); return;}
    for(;x2+x1 <= x;)
    {
        swap = x2;
        x2 = x1 + x2;
        x1 = swap;
    }
    for(;x1!=0;)
    {
        if(flag==1)
        {
            if(x2<=x)
            {
                printf("1");
                x-=x2;
                flag=0;
            }
            else printf("0");
        }
        else
        {
            printf("0");
            flag=1;
        }
        swap = x1;
        x1 = x2-x1;
        x2 = swap;
    }
    printf("\n"); 
}