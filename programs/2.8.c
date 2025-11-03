#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
/*
Вам предлагается найти позицию старшего и младшего установленных битов в числе.

Посылка должна состоять из программы, считывающей со стандартного ввода число N и 
выводящей на стандартный вывод номер его старшего и младшего бита.

В случае если установленных битов в числе нет, вы должны выдать строчку "NO".
*/
int main(void)
{
    long long unsigned N,mask = 1;
    int i,young;
    if(scanf("%llu",&N));
    if(N==0) {printf("NO"); return 0;}
    for(i=0;mask<=N;i++)
    {
        if((mask&N)!=0ll) {young = i;break;}
        mask = mask<<1;
    }
    for(i;mask<=N;i++) mask = mask<<1;
    printf("%d %d\n",i-1, young);

}