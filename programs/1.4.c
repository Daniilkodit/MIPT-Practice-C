#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
Линейное Диофантово уравнение имеет вид ax + by = c, где для заданных целых a, b, c нужно найти x, y
Очевидно пар может быть много или вообще не быть
Посылка должна состоять из программы,
считывающей со стандартного ввода три числа a, b, c и выводящей на стандартный вывод числа x и y
Используйте тип int для всех чисел
Если возможных пар много, можно вывести любую из них
Если решений нет, нужно вывести NONE
*/
int Abs(int x);
int Mod(int x,int y);
void Solve_Diof(int a,int b,int c);
int main(void)
{
    int a, b, c, res;
    res = scanf("%d%d%d",&a,&b,&c);
    if(res != 3)
    {
        printf("Error\n");
        abort();
    }
    Solve_Diof(a,b,c);
}
void Solve_Diof(int a,int b,int v)
{
    int a1 = 0,b1 =1 ,a2 = 1,b2 = 0;
    int d = b, c = a, q,r,swap;
    
    if(b == 0)
    {
        if(Mod(v,a)!=0) {printf("NONE\n");return;}
        else
        {
            printf("%d 0\n",v/a);
            return;
        }
    }
    else if(a==0)
    {
        if(Mod(v,b)!=0) {printf("NONE\n");return;}
        else
        {
            printf("0 %d\n",v/b);
            return;
        }
    }
    else
    {
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
        if(Mod(v,d) == 0)
        {
            printf("%d %d",(v/d)*a1,(v/d)*b1);
            return;
        }
        else { printf("NONE\n");return;}
    }

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