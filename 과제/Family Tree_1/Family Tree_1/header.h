#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 15

enum { FALSE, TRUE };

// 가계도를 만들기 위한 노드
typedef struct node *treePointer;
typedef struct node {
	char name;
	treePointer father;	// LeftChild
	treePointer mother; // RightChild
} node;

// 큐 만들기
typedef struct {
	char dir;
	treePointer node;
} element;
element	stack[MAX_STACK_SIZE];
int top = -1;

// 트리와 관련된 함수들 
treePointer CreateNode(char nData);
void PreOrderTraverse(treePointer ptr);
int ExistNode(treePointer ptr, char nData);
treePointer ExistNodeLocation(treePointer ptr, char nData);
void pathFinding(treePointer ptr, char nData);

// 스택에 관한 함수
void stackPush(element item);
int stackEmpty();
int stackFull();
element stackPop();
void stackFlush();