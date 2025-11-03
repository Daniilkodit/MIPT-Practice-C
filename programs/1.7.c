#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
Вам на вход приходят числа a, b и n.
Ваша задача: написать программу выдающую на стандартный вывод a ^^ b mod n.
*/
void Sverh_deg(unsigned a,unsigned b,unsigned m);
int main(void)
{
    unsigned a,b,n;
    int res;
    res = scanf("%u%u%u",&a,&b,&n);
    if(res!=3 || n == 0)
    {
        printf("Error\n");
        abort();
    }
    Sverh_deg(a,b,n);
}
void Sverh_deg(unsigned a,unsigned b,unsigned m)
{
    unsigned mult =a%m,pr;
    unsigned k = a;
    int i;
    pr = 1;
    if(b==0) {printf("1\n"); return;}
    if(b==1){printf("%u\n",a);return;}
    for(i=1;i<b;i++)
    {
        
        pr = 1;
        while(k>0)
        {
            if(k%2==1)
            {
                pr = (pr*mult)%m;
                
            }
            mult = (mult * mult)%m;
            k /=2;
        }
        mult = pr%m;
        
        k = a;
    }
    printf("%u\n",pr);
}