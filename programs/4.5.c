struct node_t
{
	struct node_t* next;
	int num;
}
unsigned cycle_len(generator_t gen)
{
	struct node_t* node= calloc(1, sizeof(struct node_t));
	struct node_t* top,runner;
	int cnt = 0,proof = 0,len_loop;
	node->next = calloc(1, sizeof(struct node_t));
	top = node;
	runner = top;
	while(1)
	{
		
		node->next->num = gen(node->num);
		node = node->next;
		cnt++;
		if(node->num == top->num)
		{
			proof = cnt;
			len_loop = cnt;
			while(proof!=0)
			{
				runner = runner->next;
				node->next->num = gen(node->num);
                		node = node->next;
                		cnt++;
				if(runner->num == node->num) proff--;
				else break;
			}
			if(proof == 0) return len_loop;
			else runner = top;
		}

	}
	return 0;

}
