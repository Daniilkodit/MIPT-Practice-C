void merge(int *arr, int l, int m, int r) {
	int*mas;
	int left = l, right = m+1,i = 0;
	mas = malloc(sizeof(int) * ((r-l)+1));
	while(left<=m && right<=r)
	{
		if(arr[left]<arr[right])
		{
			mas[i] = arr[left];
			i++;
			left++;
		}
		else
		{
			mas[i] = arr[right];
                        i++;
			right++;
		}
	}
	while(left<=m) 
	{
		mas[i] = arr[left];
                i++;
                left++;
	}
	while(right<=r)
        {
                mas[i] = arr[right];
                i++;
                right++;
        }
	for(i = l;i<=r;i++) arr[i] = mas[i-l];
	free(mas);
}

