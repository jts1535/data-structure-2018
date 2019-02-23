#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 15

enum { FALSE, TRUE };

// ���赵�� ����� ���� ���
typedef struct node *treePointer;
typedef struct node {
	char name;
	treePointer father;	// LeftChild
	treePointer mother; // RightChild
} node;

// ť �����
typedef struct {
	char dir;
	treePointer node;
} element;
element	stack[MAX_STACK_SIZE];
int top = -1;

// Ʈ���� ���õ� �Լ��� 
treePointer CreateNode(char nData);
void PreOrderTraverse(treePointer ptr);
int ExistNode(treePointer ptr, char nData);
treePointer ExistNodeLocation(treePointer ptr, char nData);
void pathFinding(treePointer ptr, char nData);

// ���ÿ� ���� �Լ�
void stackPush(element item);
int stackEmpty();
int stackFull();
element stackPop();
void stackFlush();