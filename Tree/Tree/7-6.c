#include <stdio.h> 
#include <stdlib.h>
#define SWAP(a, b, temp) ((temp) =(a),(a) = (b),(b) = (temp))

typedef struct element {
	int key;
}element;

void heapsort(element a[], int n) {
	int i, j;
	element temp;

	// 초기화
	for (i = n / 2; i > 0; i--) {
		adjust(a, i, n);
	}
	// 뺄 때마다(swap해주고) adjust
	for (i = n - 1; i > 0; i--) {
		SWAP(a[1], a[i + 1], temp);
		adjust(a, 1, i);
	}
}

void adjust(element a[], int root, int n) {	// a는 heap상태의 배열, root는 binary tree로 나타낼 때의 루트노드, n은 노드수
	int child, rootkey;
	element temp;
	rootkey = a[root].key;
	temp = a[root];
	child = root*2;

	while (child <= n) {
		if ((child < n) && (a[child].key < a[child + 1].key)) {
			child++;
		}
		if (rootkey > a[child].key) break;
		else {
			a[child / 2] = a[child];
			child *= 2;
		}
	}
	a[child] = temp;
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
