#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define HEAP_FULL(n) (n == MAX_ELEMENT -1)
#define HEAP_EMPTY(n) (!n)

// 힙에 관한 선언
typedef struct element {
	int key;
}element;
element heap[MAX_ELEMENT];
int n = 0;	// 노드수

// 최대히프상태의 이진트리에서의 노드 삽입
// 가장 오른쪽에 있는 leaf node에 넣고 adjust하기
void push(element item, int* n) {
	if (HEAP_FULL(*n)) {
		fprintf(stderr, "Heap is full.\n");
		exit(EXIT_FAILURE);
	}
	int i;
	i = ++(*n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {	// 삭제한 후의 노드가 하나 이상이고, key값이 부모노드보다 크면 
		heap[i] = heap[i / 2];	// adjust하는 과정
		i /= 2;
	}
	heap[i] = item;
}
void push(element item, int* n) {
	int i;
	i = ++(*n);
	while ((i != 1) && (item.key > heap[i].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
	
}

// 최대히프상태의 이진트리에서의 노드 삭제
element pop(int* n) {
	int parent, child;
	element item, temp; // item은 삭제할 루트노드, temp는 rightmost leaf노드
	if (HEAP_EMPTY(*n)) {
		fprintf(stderr, "Heap is empty.\n");
		exit(EXIT_FAILURE);
	}
	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	// 이 부분 알고리즘 다시 이해하기
	while (child <= *n) {
		if ((child < *n) && (heap[child].key < heap[child + 1].key)) {	// 더 큰 수가 있다면 한 칸 이동!
			child++;
		}
		if (temp.key >= heap[child].key) break;
		heap[parent].key = heap[child].key;
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}
element pop(int* n) {
	int parent, child;
	element item, temp; // item은 삭제할 루트 노드, temp는 rightmost leaf node

	parent = 1;
	child = 2;
	while (child <= *n) {
		if ((child < *n) && (heap[child].key < heap[child + 1].key)) {
			child++;
		}
		if (item.key >= heap[child].key) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}
