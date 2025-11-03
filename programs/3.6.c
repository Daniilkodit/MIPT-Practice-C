typedef int (*cmp_t)(const void *lhs, const void *rhs);
void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp)
{
	int left=0,right = num,mid;
	char *one = (char*) base;
	while(left<=right)
	{
		mid = left + (right-might)/2;
		if(cmp((const void*)(one+mid*size),key)==0) return (void*)(one+mid*size);
		if(cmp((const void*)(one+mid*size),key)>0) right = mid-1;
		else left = mid+1
	}
	return (void*)(one+num*size + 1);
}
