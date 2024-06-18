#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct vector {
	size_t size;
	size_t elem_size;
	size_t capacity;
	void *data;
};

// struct vector *vec_create(size_t elem_size, size_t capacity);
void vec_print(struct vector *vec, void (*print) (const void *));
struct vector *vec_create(size_t elem_size);
void vec_push_back(struct vector *vec, void *val);
void vec_pop_back(struct vector *vec, void (*del)(void *));
void *vec_get_at(struct vector *vec, size_t index);
void vec_insert_at(struct vector *vec, size_t index, void *val,
	void (*del)(void *));
void *vec_front(struct vector *vec);
void *vec_back(struct vector *vec);
void *vec_reserve(struct vector *vec, size_t n);
void vec_clear(struct vector *vec, void (*del)(void *));

#endif // VECTOR_H 
