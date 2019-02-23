#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))) {\
		fprintf(stderr, "Insufficient Memory");\
	exit(EXIT_FAILURE);\
	}
#define MAX_STACK_SIZE 10
#define MAX_QUEUE_SIZE 10
enum {FALSE, TRUE};

// 트리 노드에 관한 선언
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

// 스택에 관한 선언
treePointer stack[MAX_STACK_SIZE];
int top = -1;

// 큐에 관한 선언
treePointer queue[MAX_QUEUE_SIZE];
int front = 0;
int rear = 0;

// inorder traverse를 하는 함수 : left-root-right순
void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		printf("&4d", ptr->data);
		inorder(ptr->rightChild);
	}
}

// preorder traverse를 하는 함수 : root-left-right순
void preorder(treePointer ptr) {
	if (ptr) {
		printf("%4d", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// postorder traverse를 하는 함수 : left-right-root순
void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%4d", ptr->data);
	}
}

// 반복문을 이용한 inorder traverse를 하는 함수 : left-root-right순
void iterInorder1(treePointer node) {
	for (;;) {
		for (; node; node = node->leftChild) {
			push(node);
		}
		node = pop();
		if (!node) break;
		printf("%4d", node->data);
		node = node->rightChild;
	}
}
void iterInorder2(treePointer node) {
	for (;;) {
		for (; node; node = node->leftChild) {
			push(node);
		}
		node = pop();
		if (!node) return;
		printf("%3d", node->data);
		node = node->rightChild;
	}
}


// level traverse를 하는 함수
void levelorder1(treePointer ptr) {
	if (!ptr) return;
	addq(ptr);
	for (;;) {
		ptr = deleteq();
		if (ptr) {
			printf("%4d", ptr->data);
			if (ptr->leftChild) addq(ptr->leftChild);
			if (ptr->rightChild) addq(ptr->rightChild);
		}
		else {
			break;
		}
	}
}
void levelorder2(treePointer ptr) {
	if (!ptr) return;
	addq(ptr);
	for(;;) {
		ptr = deleteq();
		if (ptr) {
			printf("%3d", ptr->data);
			if (ptr->leftChild) addq(ptr->leftChild);
			if (ptr->rightChild) addq(ptr->rightChild);
		}
		else {
			break;
		}
	}

}

// 스택과 관련된 함수
void push(treePointer node) {
	if (stackFull()) {
		printf("stack full\n");
	}
	stack[++top] = node;
}

treePointer pop() {
	if (stackEmpty()) {
		printf("stack empty\n");
	}
	return stack[top--];
}

int stackEmpty() {
	if (top < 0) {
		return TRUE;
	}
	return FALSE;
}

int stackFull() {
	if (top >= MAX_STACK_SIZE) {
		return TRUE;
	}
	return FALSE;
}

// 큐에 관한 함수
void addq(treePointer node) {
	if (queueFull()) {
		printf("queue full\n");
	}
	queue[++rear] = node;
}

treePointer deleteq() {
	if (queueEmpty()) {
		printf("queue empty\n");
	}
	return queue[front++];
}

int queueEmpty() {
	if (front == rear) {
		return TRUE;
	}
	return FALSE;
}

int queueFull() {
	if (rear == MAX_QUEUE_SIZE) {
		return TRUE;
	}
	return FALSE;
}