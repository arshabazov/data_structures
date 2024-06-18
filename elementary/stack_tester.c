#include <string.h>
#include <stdio.h>

#include "stack.h"

struct person {
	char *name;
	int age;
};

void print_person(const void *data) {
	if (!data)
		return ;
	struct person *p = (struct person *)data;
	printf("name: %s, age: %d\n", p->name, p->age);
}

void del_person(void *person) {
	struct person *p = (struct person *)person;
	free(p->name);
}

int main() {
	struct stack *st;

	st = stack_create();
	if (stack_empty(st))
		printf("stack is empty\n");
	
	struct person p1 = {strdup("Andy"), 23};
	struct person p2 = {strdup("Ian"), 17};
	struct person p3 = {strdup("David"), 35};

	stack_push(st, (void *)&p1);
	stack_push(st, (void *)&p2);
	stack_push(st, (void *)&p3);
	stack_print(st, print_person);

	stack_pop(st, del_person);
	stack_print(st, print_person);

	struct node *top = stack_top(st);
	print_person((void *)top->data);

	return 0;
}
