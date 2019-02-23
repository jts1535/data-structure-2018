#include <stdio.h>
#include <stdlib.h>

// TRUE�� FALSE ������ ��� ����
enum { FALSE, TRUE };

// node�ڷ��� ����� node�� ����Ű�� treePointer ����
typedef struct node *treePointer;
typedef struct node
{
	char name;
	treePointer father;
	treePointer mother;
} node;

// Ʈ���� root�� ����Ű�� ������ root
treePointer root = NULL;

// Ʈ���� ���õ� �Լ���
treePointer CreateNode();
void Father(char parent, char child);
void Mother(char parent, char child);
void PathFinding(treePointer first, char nData);
void Preorder(treePointer ptr);
treePointer ExistNode(treePointer ptr, char nData);
treePointer ParentFinding(treePointer ptr, char target, char gender);