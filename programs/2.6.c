#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
// Impossible
/*
Число 197 называется циркулярным простым,
поскольку простыми являются все циклические перестановки его разрядов: 197 -> 971 -> 719
Необходимо для заданного числа N определить ближайшее к нему циркулярное простое.
Например для числа 200 ближайшим циркулярным простым будет 197
Посылка должна состоять из программы,
считывающей со стандартного ввода число N и
выводящей на стандартный вывод ближайшее к нему циркулярное простое число P
Вы можете предполагать, что N < 10^6
*/
struct sieve_t {
    unsigned int n;
    unsigned char *s;
};
void fill(struct sieve_t *sv )
{
    int i,j;
    sv->s[1]=1;
    sv->s[0]=1;
    for(i = 2 ;i*i<sv->n;i++)
    {
        if(sv->s[i]==0)
        {
            for(j = i*i;j<sv->n;j+=i) sv->s[j]=1;
        }
    }
}
int Reverse(int n)
{
	int reverse = 0,count = 10;
	while(n/10!=0)
	{
		if(n%10==0) {reverse = 0;break;}
		reverse += (n%10)*count;
		count*=10;
		n/=10;
	}
	return (reverse+n);
}
int check(int num,struct sieve_t* sv)
{
	int start = num;
	if(sv->s[num]) return 0;
	num = Reverse(num);
	while(num!=start)
	{
		if(sv->s[num]) return 0;
		else num = Reverse(num);
	}
	return 1;

}

int main(void)
{
    struct sieve_t sv;
    int N,left,right, answer = 0;
    
    if(scanf("%d",&N)!=1) abort();
    sv.n = 999999;
    sv.s = calloc(sv.n,sizeof(char));
    fill(&sv);
    left = N-1;
    right = N;
    while(right<1000000 && left>0)
    {
	    if(check(right,&sv)==1){answer = right;break;}
	    else right++;
	    if(check(left,&sv)==1) {answer = left;break;}
	    else left--;
	    
    }
    while(left>0 && answer==0)
    {
	    if(check(left,&sv)==1) {answer = left;break;}
            else left--;
    }
    while(right<1000000 && answer==0)
    {
	    if(check(right,&sv)==1){answer = right;break;}
            else right++;
    }
    printf("%d\n",answer);
    return 0;
}












