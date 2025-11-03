int dlina(struct node_t *rabbit,struct node_t *turtle);
int loop_len(struct node_t *top)
{
        struct node_t *turtle = top,*rabbit = top;
        if(top == NULL) return 0;
        while(rabbit!= NULL)
        {
                rabbit = rabbit->next;
                if(rabbit == NULL) return 0;
                if(rabbit == turtle) return dlina(rabbit,turtle);

                rabbit = rabbit->next;
                if(rabbit == NULL) return 0;
                if(rabbit == turtle) return dlina(rabbit,turtle);
                turtle = turtle->next;
        }
        return 0;
}
int dlina(struct node_t *rabbit,struct node_t *turtle)
{
        int count = 1;
        rabbit = rabbit->next;
        while(rabbit != turtle)
        {
                rabbit = rabbit->next;
                count++;
        }
        return count;
}	
