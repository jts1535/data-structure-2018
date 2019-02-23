#include <stdio.h>
#include <stdlib.h>

// TRUE와 FALSE 열거형 상수 선언
enum { FALSE, TRUE };

// node자료형 선언과 node를 가리키는 treePointer 선언
typedef struct node *treePointer;
typedef struct node
{
	char name;
	treePointer father;
	treePointer mother;
} node;

// 트리의 root를 가리키는 포인터 root
treePointer root = NULL;

// 트리와 관련된 함수들
treePointer CreateNode();
void Father(char parent, char child);
void Mother(char parent, char child);
void PathFinding(treePointer first, char nData);
void Preorder(treePointer ptr);
treePointer ExistNode(treePointer ptr, char nData);
treePointer ParentFinding(treePointer ptr, char target, char gender);