struct node_t {
  struct node_t *next;
  int data;
};
int list_is_a_loop(struct node_t *top)
{
	struct node_t *turtle = top,*rabbit = top;
	if(top == NULL) return 0;
	while(rabbit!= NULL)
	{
		rabbit = rabbit->next;
		if(rabbit == NULL) return 0;
		if(rabbit == turtle) return 1;
		rabbit = rabbit->next;
		if(rabbit == NULL) return 0;
		if(rabbit == turtle) return 1;
		turtle = turtle->next;
	}
	return 0;
}
int main(void);
