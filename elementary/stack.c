#include "stack.h"

static struct node *create_node(void *val) {
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	assert(new_node);
	new_node->data = val;
	new_node->next = NULL;
	return new_node;
}

struct stack *stack_create() {
	struct stack *st;

	st = malloc(sizeof(struct stack));
	st->top = NULL;
	return st;
}

int stack_empty(const struct stack *st) {
	if (st->top == NULL)
		return 1;
	return 0;
}

void stack_push(struct stack *st, void *val) {
	if (!st || !val) return ;
	struct node *new_node = create_node(val);
	new_node->next = st->top;
	st->top = new_node;
}

void stack_print(const struct stack *st, void (*print)(const void *)) {
	if (!st || stack_empty(st)) return ;
	struct node *temp = st->top;
	while (temp) {
		(*print)(temp->data);
		temp = temp->next;
	}
}

void stack_pop(struct stack *st, void (*del)(void *)) {
	if (!st || stack_empty(st)) return ;
	struct node *temp = st->top;	
	st->top = temp->next;
	if (del)
		(*del)(temp->data);
	free(temp);
	temp = NULL;
}

struct node *stack_top(struct stack *st) {
	if (!st || stack_empty(st))
		return NULL;
	return st->top;
}


