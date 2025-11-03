#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct tree_t {
  struct tree_t *left;
  struct tree_t *right;
  int data;
};
struct stack{
  struct tree_t *node;
  struct stack *next;
};
struct tree_file_t {
  int n;
  int *topology; // 2 * n
  int *values;   // n
};
void pop_stack(struct stack** top){
        struct stack *next = (*top)->next;
        if((*top) == NULL) return;
        free((*top));
        (*top) = next;
}
void push_stack(struct stack** top,struct tree_t *data)
{
        struct stack *tmp = calloc(1,sizeof(struct stack));
        tmp->node = data;
        tmp->next = (*top);
        (*top) = tmp;

}
struct tree_file_t readfile(FILE *f) {
  struct tree_file_t ret;
  int res, i;

  res = fscanf(f, "%d", &ret.n);
  assert(res == 1);

  ret.topology = calloc(2 * ret.n, sizeof(int));
  ret.values = calloc(ret.n, sizeof(int));

  for (i = 0; i < 2 * ret.n; ++i) {
    res = fscanf(f, "%d", ret.topology + i);
    assert(res == 1);
  }

  for (i = 0; i < ret.n; ++i) {
    res = fscanf(f, "%d", ret.values + i);
    assert(res == 1);
  }

  return ret;
}

void free_temp(struct tree_file_t data) {
  free(data.topology);
  free(data.values);
}

void free_tree(struct tree_t *top) {
  if (top == NULL)
    return;
  free_tree(top->left);
  free_tree(top->right);
  free(top);
}

struct tree_t *create_node(int data, struct tree_t *l, struct tree_t *r) {
  struct tree_t *ret = malloc(sizeof(struct tree_t));
  assert(ret);

  ret->left = l;
  ret->right = r;
  ret->data = data;
  return ret;
}

struct tree_t *do_recover(struct tree_file_t data, int *cursor, int *curval) {
  struct tree_t *n = NULL;
  int cur = *cursor;
  int curv = *curval;
  *cursor += 1;
  if (cur < (data.n * 2) && data.topology[cur] == 1) {
    struct tree_t *l, *r;
    *curval += 1;
    l = do_recover(data, cursor, curval);
    r = do_recover(data, cursor, curval);
    assert(curv < data.n);
    n = create_node(data.values[curv], l, r);
  }
  return n;
}

struct tree_t *recover(struct tree_file_t data) {
  int cursor = 0;
  int curval = 0;
  return do_recover(data, &cursor, &curval);
}
int ch_tr_bal(struct tree_t *top,int left, int right)
{
	if(top==NULL) return 1;
	if(left<=top->data && top->data<=right)
	{
		return ch_tr_bal(top->left,left,top->data) * ch_tr_bal(top->right,top->data,right);
	}
	return 0;
}

int check_is_bst(struct tree_t *top)
{
	
	return ch_tr_bal(top,-INT_MAX,INT_MAX);
}
int main() {
  int is_search;
  struct tree_t *top;
  struct tree_file_t filetree;

  // read tree from file
  filetree = readfile(stdin);

  // recover tree
  top = recover(filetree);

  // check if search
  is_search = check_is_bst(top);

  printf("%d\n", is_search);

  // free everything
  free_tree(top);
  free_temp(filetree);
}
