#include "vector.h"

static void vec_expand(struct vector *vec) {
	vec->data = realloc(vec->data, sizeof(struct vector) *
		(vec->size * vec->elem_size * 2));
}

void vec_print(struct vector *vec, void (*print) (const void *)) {
	if (!vec) return ;
	for (int i = 0; i < vec->size; i++)
		print(vec->data + i * vec->elem_size);
}

struct vector *vec_create(size_t elem_size) {
	struct vector *vec = malloc(sizeof(struct vector));
	assert(vec);
	vec->size = 0;
	vec->elem_size = elem_size;
	vec->capacity = 0;

	return vec;
}

void vec_push_back(struct vector *vec, void *val) {
	if (!vec || !val) return ;
	if (vec->size == 0) {
		vec->data = malloc(sizeof(vec->elem_size));
		assert(vec->data);
		vec->capacity = 1;
	} else if (vec->size == vec->capacity)
		vec_expand(vec);
	void *ptr = (char *)vec->data + vec->size * vec->elem_size;
	memcpy(ptr, val, vec->elem_size);
	vec->size++;
}

void vec_pop_back(struct vector *vec, void (*del)(void *)) {
	if (!vec) return ;
	if (del) {
		void *elem_ptr = (char *)vec->data + (vec->size - 1) * vec->elem_size;
		(*del)(elem_ptr);
	}
	vec->size--;
}

void vec_clear(struct vector *vec, void (*del)(void *)) {
	if (!vec) return ;
	if (del) {
		for (int i = 0; i < vec->size; i++) {
			(*del)(vec->data + i * vec->elem_size);
		}
	}
	free(vec->data);
	free(vec);
	vec = NULL;
}

void *vec_front(struct vector *vec) {
	if (!vec)
		return NULL;
	return vec->data;
}

void *vec_back(struct vector *vec) {
	if (!vec)
		return NULL;
	return vec->data + (vec->size - 1) * vec->elem_size;
}

void *vec_get_at(struct vector *vec, size_t index) {
	if (!vec)
		return NULL;
	if (index >= vec->size)
		return NULL;
	return vec->data + index * vec->elem_size;
}
void vec_insert_at(struct vector *vec, size_t index, void *val,
	void (*del)(void *))
{
	if (!vec || index >= vec->size)
		return ;
	void *ptr = vec->data + index * vec->elem_size;
	if (del)
		(*del)(ptr);
	memcpy(ptr, val, vec->elem_size);
}

void *vec_reserve(struct vector *vec, size_t n) {
}

#if 0
struct vector *vec_create(size_t elem_size, size_t capacity) {
	struct vector *vec = malloc(sizeof(struct vector));
	assert(vec);
	vec->size = 0;
	vec->elem_size = elem_size;
	vec->capacity = capacity;
	vec->data = malloc(sizeof(elem_size * capacity));
	assert(vec->data);

	return vec;
}
#endif
