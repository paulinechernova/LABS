#include"heap.h"

void MAKE(heap* Heap, size_t key_size, size_t value_size, fType CMP) {
	Heap->size=1;
	Heap->current=1;
	Heap->key_size=key_size;
	Heap->value_size=value_size;
	Heap->CMP=CMP;
	Heap->elements=(pair*)malloc(sizeof(pair));
	Heap->elements[0].key=malloc(Heap->key_size);
	Heap->elements[0].value=malloc(Heap->value_size);
}

void CLEAR(heap* Heap) {
	int i;
	for (i=0; i<Heap->size; i++) {
		free(Heap->elements[i].key);
		free(Heap->elements[i].value);
	}
	free(Heap->elements);
}

void swap(pair* a, pair* b) {
	pair tmp=*a; 
	*a=*b;
	*b=tmp;
}

void LIFT(heap* Heap, int number) {
	while (number>1 && Heap->CMP(Heap->elements[number].key, Heap->elements[number/2].key)>0) {
		swap(&(Heap->elements[number]), &(Heap->elements[number/2]));
		number/=2;
	}
}

void SIFT(heap* Heap, int number) {
	while (2*number<Heap->current) {
		int p=2*number;
		if (p<Heap->current && Heap->CMP(Heap->elements[p+1].key, Heap->elements[p].key)>0)
			p++;
			
		if (Heap->CMP(Heap->elements[number].key, Heap->elements[p].key)>0)
			break;
			
		swap(&(Heap->elements[number]), &(Heap->elements[p]));
		number=p;
	}
}

void CHANGE_KEY(heap* Heap, void* key, void* new_key) {
	int i;
	for (i=1; i<Heap->current; i++) {
		if (Heap->CMP(Heap->elements[i].key, key)==0) {
			memcpy(Heap->elements[i].key, new_key, Heap->key_size);
			SIFT(Heap, i);
			LIFT(Heap, i);
			return;
		}
	}
}

pair EXTRACT_MAX(heap* Heap) {
	memmove(Heap->elements[0].key, Heap->elements[1].key, Heap->key_size);
	memmove(Heap->elements[0].value, Heap->elements[1].value, Heap->value_size);
	
	--Heap->current;
	
	memmove(Heap->elements[1].key, Heap->elements[Heap->current].key, Heap->key_size);
	memmove(Heap->elements[1].value, Heap->elements[Heap->current].value, Heap->value_size);
	SIFT(Heap, 1);
	return Heap->elements[0];
}

void ADD(heap* Heap, void* key, void* value) {
	
	if (Heap->current==Heap->size) {
		Heap->elements=(pair*)realloc(Heap->elements,sizeof(pair)*Heap->size*2);
		int i;
		for (i=Heap->current; i<Heap->size*2; i++) {
			Heap->elements[i].key = malloc(Heap->key_size);
			Heap->elements[i].value = malloc(Heap->value_size);
		}
		Heap->size*=2;
	}
	
	memcpy(Heap->elements[Heap->current].key, key, Heap->key_size);
	memcpy(Heap->elements[Heap->current].value, value, Heap->value_size);
	
	LIFT(Heap, Heap->current);
	Heap->current++;
}	

void HEAPSORT(void* a, size_t data_size, int n, fType CMP) {
	
	heap Heap;
	MAKE(&Heap, data_size, data_size, CMP);
	
	int i;
	for (i=0; i<n; i++)
		ADD(&Heap, a+i*data_size, a+i*data_size);
		
	for (i=0; i<n; i++) {
		pair answer = EXTRACT_MAX(&Heap);
		memmove(a+i*data_size, answer.key, data_size);
	}
	
	CLEAR(&Heap);
}
