#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
Дано целое положительное число x и целый положительный модуль m
Будем обозначать fib(x) = число Фибоначчи под номером x
fib(0) = 0
fib(1) = 1
fib(90) = 2880067194370816120
Вам необходимо написать программу, которая вычисляет fib(x) по модулю m
Посылка должна состоять из программы,
 считывающей со стандартного ввода два числа x и m и выводящей на стандартный вывод число fib(x) mod m
*/
unsigned Fib(unsigned x,unsigned m);
int main(void)
{
    unsigned x,m;
    int res;
    res = scanf("%u%u",&x,&m);
    if(res!=2)
    {
        printf("Error\n");
        abort();
    }
    printf("%u\n",Fib(x,m));
}
unsigned Fib(unsigned x,unsigned m)
{
    unsigned x1 = 0, x2 = 1,swap;
    int i;
    if(x==1) return 1;
    if(x==0) return 0;
    for(i=2;i<=x;i++)
    {
        swap = x2;
        x2 = (x1 +x2)%m;
        x1 = swap;
    }
    return x2;
}