typedef int (*cmp_t)(void const * lhs, void const * rhs);
int selstep(void * parr, int eltsize, int numelts, int nsorted, cmp_t cmp)
{
    int i,ind_max = nsorted;
    unsigned char * arr = (unsigned char*) parr;
    unsigned char *f,*e,temp;
    for(i=nsorted+1;i<numelts;i++)
    {
        if(cmp((const void *)(arr+i*eltsize),(const void *)(arr+ind_max*eltsize))==1)
        {
            ind_max = i;
        }
    }
    f = ((unsigned char*) parr)+ind_max*eltsize;
    e = ((unsigned char*) parr)+nsorted*eltsize;
    for(i=0;i<eltsize;i++)
    {
        temp = f[i];
        f[i] = e[i];
        e[i] = temp;
    }
    return 0;
}
