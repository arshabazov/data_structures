#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <assert.h>

struct node {
	void *data;
	struct node *next;
};

struct stack {
	struct node *top;
};

struct stack *stack_create();
int stack_empty(const struct stack *st);
void stack_push(struct stack *st, void *val);
void stack_pop(struct stack *st, void (*del)(void *));
struct node *stack_top(struct stack *st);
void stack_print(const struct stack *st, void (*print)(const void *));

#endif // STACK_H
