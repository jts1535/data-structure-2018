#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define HEAP_FULL(n) (n == MAX_ELEMENT -1)
#define HEAP_EMPTY(n) (!n)

// ���� ���� ����
typedef struct element {
	int key;
}element;
element heap[MAX_ELEMENT];
int n = 0;	// ����

// �ִ����������� ����Ʈ�������� ��� ����
// ���� �����ʿ� �ִ� leaf node�� �ְ� adjust�ϱ�
void push(element item, int* n) {
	if (HEAP_FULL(*n)) {
		fprintf(stderr, "Heap is full.\n");
		exit(EXIT_FAILURE);
	}
	int i;
	i = ++(*n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {	// ������ ���� ��尡 �ϳ� �̻��̰�, key���� �θ��庸�� ũ�� 
		heap[i] = heap[i / 2];	// adjust�ϴ� ����
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

// �ִ����������� ����Ʈ�������� ��� ����
element pop(int* n) {
	int parent, child;
	element item, temp; // item�� ������ ��Ʈ���, temp�� rightmost leaf���
	if (HEAP_EMPTY(*n)) {
		fprintf(stderr, "Heap is empty.\n");
		exit(EXIT_FAILURE);
	}
	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	// �� �κ� �˰��� �ٽ� �����ϱ�
	while (child <= *n) {
		if ((child < *n) && (heap[child].key < heap[child + 1].key)) {	// �� ū ���� �ִٸ� �� ĭ �̵�!
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
	element item, temp; // item�� ������ ��Ʈ ���, temp�� rightmost leaf node

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
