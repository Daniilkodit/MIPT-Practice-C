#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void Pizano(unsigned long x, unsigned long m);
unsigned long Fib(unsigned long x, unsigned long m);

int main(void)
{
    unsigned long x, m;
    int res;
    res = scanf("%lu%lu", &x, &m);
    if(res != 2)
    {
        printf("Error\n");
        abort();
    }
    Pizano(x, m);
    return 0;
}

void Pizano(unsigned long x, unsigned long m)
{
    unsigned long x1 = 0, x2 = 1, swap;
    unsigned long period = 0;
    if(m == 1 || m == 0) {
        printf("0 %lu\n", m); 
        return;
    }
    do
    {
        swap = x2;
        x2 = (x1 + x2) % m;
        x1 = swap;
        period++;
    } while (x1 != 0 || x2 != 1);
    x = x % period;
    x = Fib(x, m);
    printf("%lu %lu\n", x, period);
}

unsigned long Fib(unsigned long x, unsigned long m)
{
    unsigned long x1 = 0, x2 = 1, swap;
    unsigned long i;
    if(x == 1) return 1;
    if(x == 0) return 0;
    for(i = 2; i <= x; i++)
    {
        swap = x2;
        x2 = (x1 + x2) % m;
        x1 = swap;
    }
    return x2;
}