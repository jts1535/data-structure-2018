#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))) {\
		fprintf(stderr, "Insufficient Memory"); \
	exit(EXIT_FAILURE); \
	}
#define MAX(a, b) (a > b)?a:b
#define MAX_STACK_SIZE 10
enum {FALSE, TRUE};

// Ʈ�� ��忡 ���� ����
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

// ���ÿ� ���� ����
typedef struct element {
	treePointer node;
	char dir;
} element;
element stack[MAX_STACK_SIZE];
int top = -1;

// ���� Ʈ���� �����ϴ� �Լ�
treePointer copy1(treePointer original) {
	treePointer temp;
	if (original) {
		temp->leftChild = copy(original->leftChild);
		temp->rightChild = copy(original->rightChild);
		temp->data = original->data;
		return temp;
	}
	else {
		return NULL;
	}
}
treePointer copy2(treePointer original) {
	treePointer temp;
	if (original) {
		temp = original;
		temp->leftChild = copy2(temp->leftChild);
		temp->rightChild = copy2(temp->rightChild);
		temp->data = original->data;
		return temp;
	}
	else {
		return NULL;
	}
}

// �� ���� Ʈ���� �Ȱ������� �Ǵ��ϴ� �Լ�
int equal1(treePointer first, treePointer second) {
	return((!first) && (!second)) ||	// �� �� ������ ���
		(first && second	// �� �� ���尡 �ƴ� ���
		&& equal(first->leftChild, second->leftChild) // ���� tree
		&& equal(first->rightChild, second->rightChild)		// ������ tree
		&& (first->data == second->data));	// root
}
int equal2(treePointer first, treePointer second) {
	return (((!first) && (!second)) ||
		(first && second
			&& equal2(first->leftChild, second->leftChild)
			&& equal2(first->rightChild, second->rightChild)
			&& (first->data == second->data)));
}

// ����Ʈ���� ������ ��ȯ�ϴ� �Լ�
int numNode1(treePointer ptr) {
	if (!ptr) return 0;
	int numOfLeft = numNode(ptr->leftChild);
	int numOfRight = numNode(ptr->rightChild);
	return 1 + numOfLeft + numOfRight;
}
int numNode2(treePointer ptr) {
	if (!ptr) return 0;
	int numOfRight = numNode1(ptr->rightChild);
	int numOfLeft = numNode2(ptr->leftChild);
	return 1 + numOfRight + numOfLeft;
}

// ����Ʈ���� ���̼��� ��ȯ�ϴ� �Լ�
int treeHeight1(treePointer ptr) {
	if (!ptr) return 0;
	int heightLeft = treeHeight(ptr->leftChild);
	int heightRight = treeHeight(ptr->rightChild);
	return 1 + MAX(heightLeft, heightRight);
}
int treeHeight2(treePointer ptr) {
	if (!ptr) return 0;
	int heightofL = treeHeight2(ptr->leftChild);
	int heightofR = treeHeight2(ptr->rightChild);
	return 1 + MAX(heightofL, heightofR);
}

// ����Ʈ������ Ư�� data�� �����ϴ����� �˷��ִ� �Լ�
int existNode1(treePointer ptr, int value) {
	if (!ptr) return FALSE;
	if (ptr->data == value) return TRUE;
	if (existNode(ptr->leftChild, value)) return TRUE;
	return (existNode(ptr->rightChild, value));
}
int existNode2(treePointer ptr, int value) {
	if (!ptr) return FALSE;
	if (ptr->data == value) return TRUE;
	if (existNode2(ptr->leftChild, value)) return TRUE;
	return (existNode2(ptr->rightChild, value));
}

// ����Ʈ������ Ư�� data�� ��� �����͸� ��ȯ�ϴ� �Լ�
treePointer exist1(treePointer ptr, int value) {
	treePointer p;
	if (!ptr) return NULL;
	if (ptr->data == value) return ptr;
	if (p = exist(ptr->leftChild, value)) return p;
	return (exist(ptr->rightChild, value));
}
treePointer exist2(treePointer ptr, int value) {
	treePointer p;
	if (!ptr) return NULL;
	if (ptr->data == value) return ptr;
	if (p = exist(ptr->leftChild, value)) return p;
	return exist(ptr->rightChild, value);
}

// root��忡�� Ư������ ���� path�� ���ÿ� �����ϴ� �Լ�
void iterInorderPath(treePointer node, int value) {
	element e;
	for (;;) {
		for (; node; node = node->leftChild) {
			if (node->data == value) return;
			e.node = node; e.dir = 'L'; push(e);
		}
		e = pop();
		while (e.dir == 'R') e = pop();
		e.dir = 'R'; push(e);
		node = node->rightChild;
	}
}
void iterInorderPath(treePointer node, int value) {
	element e;
	for (;;) {
		for (; node; node->leftChild) {
			if (node->data == value) return;
			e.node = node; e.dir = 'L'; push(e);
		}
		e = pop();
		while (e.dir == 'R') e = pop();
		e.dir = 'R'; push(e);
		node = node->rightChild;
	}
}

// ���� ������ �Լ�
void push(element item) {
	if (stackFull()) {
		printf("stack full\n");
	}
	stack[++top] = item;
}

element pop() {
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