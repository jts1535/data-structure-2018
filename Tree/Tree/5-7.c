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

// ã�����ϴ� key���� ������ �ִ� ����� �ּҸ� ��ȯ�ϴ� �Լ�
treePointer search(treePointer root, int value) {
	if (!root) return NULL;
	if (value == root->data.key) return root;
	if (value < root->data.key) search(root->leftChild, value);
	return search(root->rightChild, value);
}

// �ݺ����� ����Ͽ� key���� ������ �ִ� ����� �ּҸ� ��ȯ�ϴ� �Լ�
treePointer iterSearch(treePointer root, int value) {
	while (root) {
		if (value == root->data.key) return root;
		if (value < root->data.key) root = root->leftChild;
		else root = root->rightChild;
	}
	return NULL;
}

// �����ϴ� �͸�...