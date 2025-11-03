#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
Вам на вход приходят числитель и знаменатель дроби.
Ваша задача: написать программу выдающую на стандартный вывод представление цепной дробью.
*/
int Abs(int x);
int Mod(int x,int y);
void Drob(int x,int y);
int main(void)
{
    int a, b, res;
    res = scanf("%d%d",&a,&b);
    if(res != 2 || b==0)
    {
        printf("Error\n");
        abort();
    }
    Drob(a,b);
    printf("\n");

}
void Drob(int x,int y)
{
    
    int res = x/y;
    if(Mod(x,y)==0) {printf("%d",res); return;}
    printf("%d ",res);
    Drob(y,Mod(x,y));
    
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