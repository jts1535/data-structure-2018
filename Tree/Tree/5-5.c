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

// 스레드 이진 트리에서 inorder succesor 탐색하는 함수
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

// 스레드 이진 트리의 inorder traverse를 하는 함수
void tinorder(threadedPointer tree) {
	threadedPointer temp = tree;
	for (;;) {
		temp = insucc(temp);
		if (temp == tree) break;	// 다시 돌아왔다.. 끝이다.
		printf("%3c", temp->data);
	}
}

