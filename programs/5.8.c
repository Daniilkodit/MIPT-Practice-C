#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#define MAX_MATCHES 10000
void reading(char**s,int*n)
{
        scanf("%d",n);
        getchar();
        (*s) = (char*)malloc((*n)+1);
        for(int i = 0;i<(*n) && scanf("%c",&(*s)[i]);i++){}
        (*s)[(*n)] = 0;

}
int main()
{
        regmatch_t matches[MAX_MATCHES];
        int n,m,start,end;
        char*subs,*s,tmp;
        regex_t regex;
        reading(&subs,&n);
        getchar();
        reading(&s,&m);
        regcomp(&regex,subs,REG_EXTENDED);
        regexec(&regex,s,MAX_MATCHES,matches,0);
        for(int i =0;i<regex.re_nsub + 1;i++)
        {
                start = matches[i].rm_so;
                end = matches[i].rm_eo-1;
                for(int j = 0;j<=(end-start+1)/2;j++)
                {
                        tmp = s[start+j];
                        s[start+j] = s[end-j];
                        s[end-j] = tmp;
                }
        }
        for(int i = 0;i<m;i++)
        {
                printf("%c",s[i]);
        }
}
