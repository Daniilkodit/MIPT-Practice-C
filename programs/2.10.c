#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "u_template.h"
void fill_sieve(struct sieve_t *sv)
{
    unsigned i,j;
    sv->s[0] |= 0x03;
    for(i = 2 ;i*i<sv->n*8;i++)
    {
        if((sv->s[(i/8)]&(1u<<(i%8)))==0)
        {
            for(j = i*i;j<sv->n*8;j+=i)
            {
                sv->s[(j/8)]|=(1u<<(j%8));
            }
        }
    }
}
int is_prime(struct sieve_t *sv, unsigned n)
{
    return !((sv->s[n/8])&(1<<(n%8)));
}
int main(void)
{
    struct sieve_t sv;
    unsigned char mask;
    sv.n = 10;
    sv.s = calloc(10,sizeof(unsigned char));
    fill_sieve(&sv);
    for(int i = 0;i<10;i++)
    {
        mask=1;
        for(int j = 0;j<8;j++)
        {
            
            printf("  %u ",(sv.s[i]&mask)!=0);
            mask = mask<<1;
        }
        printf("\n");
        for(int j = 0;j<8;j++) printf("  %d ",j+i*8);
        printf("\n");
    }
    printf("%d\n",is_prime(&sv,24));
}