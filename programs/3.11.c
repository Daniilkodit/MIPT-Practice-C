int majority_element(const int *parr, int len)
{
	int maj_el = parr[0],count = 1,i;
	for(i = 1;i<len;i++)
	{
		if(maj_el == parr[i]) count++
		else if(maj_el != parr[i] && count>0) count--;
		else
		{
			maj_el = parr[i];
			count = 1;
		}
	}
	return maj_el;
}
