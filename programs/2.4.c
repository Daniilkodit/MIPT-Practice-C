#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "u_template.h"
/*
Вам заранее задан тип данных решета
struct sieve_t {
  int n;
  char *s;
};
Ваша задача написать две функции с заданными наперёд именами и прототипами: fill_sieve и nth_prime
void fill_sieve(struct sieve_t *sv);
Функция fill_sieve заполняет решето, при этом инверсный признак хранится в каждом байте,
 то есть после работы этой функции sv->s[2] == 0, sv->s[3] == 0, sv->s[4] == 1 и т.д.
Считайте, что на входе sv->n уже выставлено и sv->s уже аллоцировано не менее,
чем в sv->n байт и инициализировано нулями. Выделения памяти в этой функции не происходит
int nth_prime(struct sieve_t *sv, int N)
Функция nth_prime ищет N-е простое число (первым является 2, шестым 13) используя решето s
Предполагается, что решето корректно заполнено как минимум до N(logN + loglogN) предыдущей функцией
Посылка должна состоять из этих двух функций (допустимо также любое количество вспомогательных
 и не должна содержать функцию main
*/
void fill_sieve(struct sieve_t *sv)
{
    int i,j;
    for(i = 2 ;i*i<sv->n;i++)
    {
        if(sv->s[i]==0)
        {
            for(j = i*i;j<sv->n;j+=i) sv->s[j]=1;
        }
    }
}
int nth_prime(struct sieve_t *sv, int N)
{
    int count = 0;
    int i;
    for(i = 2;i<sv->n;i++)
    {
        if(sv->s[i]==0)
        {
            count++;
            if(count==N) return i;
        }
    }
    return 0;
}