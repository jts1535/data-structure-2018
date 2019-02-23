#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int key;
}element;

typedef struct node* treePointer;
typedef struct node {
	element data;
	treePointer leftChild, rightChild;
} node;

// 찾고자하는 key값을 가지고 있는 노드의 주소를 반환하는 함수
treePointer search(treePointer root, int value) {
	if (!root) return NULL;
	if (value == root->data.key) return root;
	if (value < root->data.key) search(root->leftChild, value);
	return search(root->rightChild, value);
}

// 반복문을 사용하여 key값을 가지고 있는 노드의 주소를 반환하는 함수
treePointer iterSearch(treePointer root, int value) {
	while (root) {
		if (value == root->data.key) return root;
		if (value < root->data.key) root = root->leftChild;
		else root = root->rightChild;
	}
	return NULL;
}

// 삽입하는 것만...