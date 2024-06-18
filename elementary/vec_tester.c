#include <stdio.h>
#include "vector.h"

struct person {
	char *name;
	int age;
};

void print_int(const void *data) {
	int *n = (int *)data;
	printf("%d ", *n);
}

void print_person(const void *data) {
	if (!data)
		return ;
	struct person *p = (struct person *)data;
	printf("person name: %s, person age: %d\n", p->name, p->age);
}

void del_person(void *person) {
	struct person *p = (struct person *)person;
	free(p->name);
}

int main() {
	struct vector *vec;
	struct person p1 = {strdup("Andy"), 23};
	struct person p2 = {strdup("Ian"), 17};
	struct person p3 = {strdup("David"), 35};

	vec = vec_create(sizeof(struct person));
	vec_push_back(vec, &p1);
	vec_push_back(vec, &p2);
	vec_push_back(vec, &p3);

	struct person p = {strdup("Venom Snake"), 40};
	vec_insert_at(vec, 2, &p, del_person); 
	struct person *ptr = (struct person *)vec_get_at(vec, 2);
	printf("Person info\nname: %s\nage: %d\n", ptr->name, ptr->age); 
	#if 0
	struct person *first = (struct person *)vec_front(vec);
	struct person *last = (struct person *)vec_back(vec);
	printf("First person info\nname: %s\nage: %d\n\n", first->name, first->age); 
	printf("Last person info\nname: %s\nage: %d\n", last->name, last->age); 
	vec_pop_back(vec, del_person);
	vec_print(vec, print_person);
	#endif
	vec_clear(vec, (void *)del_person);

	return 0;
}
