#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"heap.h"

int CMP(void* a, void* b){   
	int* first=(int*)a;
	int* second=(int*)b; 
	return *first>*second? 1 : (*first<*second ? -1 : 0) ;
}

void print(heap* Heap) {
	while (Heap->current>1){
		pair answer = EXTRACT_MAX(Heap);
		int* a = (int*)answer.key;
		int* b = (int*)answer.value;
		printf("%d %d\n", *a, *b);
	}
}


int main() {
	int value, key;
	heap Heap;
	MAKE(&Heap, sizeof(value), sizeof(key), CMP);
	
	while (scanf("%d %d", &key, &value)>0) 
		ADD(&Heap, &key, &value);
	
	print(&Heap);
	
	CLEAR(&Heap);
	
	return 0;
}
