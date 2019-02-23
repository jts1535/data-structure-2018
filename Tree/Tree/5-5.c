#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))) { \
		fprintf(stderr, "Insufficient Memory");	\
		exit(EXIT_FAILURE); \
	}

typedef struct threadedTree* threadedPointer;
typedef struct threadedTree {
	short int leftThread;
	threadedPointer leftChild;
	char data;
	threadedPointer rightThread;
	short int rightChild;
} threadedTree;

// ������ ���� Ʈ������ inorder succesor Ž���ϴ� �Լ�
threadedPointer insucc(threadedPointer tree) {
	threadedPointer temp;
	temp = tree->rightChild;
	if (!tree->rightThread) {
		while (!temp->leftThread) {
			temp = temp->leftChild;
		}
	}
	return temp;
}

// ������ ���� Ʈ���� inorder traverse�� �ϴ� �Լ�
void tinorder(threadedPointer tree) {
	threadedPointer temp = tree;
	for (;;) {
		temp = insucc(temp);
		if (temp == tree) break;	// �ٽ� ���ƿԴ�.. ���̴�.
		printf("%3c", temp->data);
	}
}

