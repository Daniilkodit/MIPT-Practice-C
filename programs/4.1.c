#include<stdio.h>
#include<stdlib.h>
struct node_t
{
  struct node_t *next;
  int data;
};
void Insert_spisok(int num,struct node_t** even);
struct node_t *read_list(FILE *inp)
{
	struct node_t *even = NULL,*odd = NULL;
	int num;
	struct node_t *tmp;
	if(inp == NULL) return NULL;
	for(;fscanf(inp,"%d",&num) == 1;)
	{
		if(num%2==0) Insert_spisok(num,&even);
		else Insert_spisok(num,&odd);
	}
	if(even == NULL) return odd;
	if(odd == NULL) return even;
	tmp = even;
	while(tmp->next != NULL) tmp = tmp->next;
	tmp->next = odd;
	fclose(inp);
	return even;	

}
void delete_list(struct node_t *top)
{
	struct node_t *tmp;
	while(top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
}	
void Insert_spisok(int num, struct node_t** head)
{
    struct node_t *new_node = calloc(1, sizeof(struct node_t));
    struct node_t *tmp = (*head);
    new_node->data = num;
    new_node->next = NULL;

    if((*head) == NULL) {
        (*head) = new_node;
    }
    else {
        while(tmp->next != NULL) 
            tmp = tmp->next;
        tmp->next = new_node;
    }
}
int main(void);
