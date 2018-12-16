#ifndef heap_h
#define heap_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int (*fType)(void*, void*);

typedef struct pair {
	
	void* value;
	void* key;
	
} pair;

typedef struct heap {
	
	int size;
	int current;
	size_t key_size;
	size_t value_size;
	fType CMP;
	pair* elements;
	
} heap;

void MAKE(heap* Heap, size_t key_size, size_t value_size, fType CMP);

pair EXTRACT_MAX(heap* Heap);

void CHANGE_KEY(heap* Heap, void* key, void* new_key);

void CLEAR(heap* Heap);

void ADD(heap* Heap, void* key, void* value);

void HEAPSORT(void* a, size_t data_size, int n, fType CMP);

#endif 
