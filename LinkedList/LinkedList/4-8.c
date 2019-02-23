// doubly circular linked list w/ header node
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))) {\
		fprintf(stderr, "Insufficient Memory"); \
		exit(EXIT_FAILRUE); \
	}

typedef struct element{
	int key;
} element;

typedef struct node* nodePointer;
typedef struct node {
	nodePointer llink;
	element data;
	nodePointer rlink;
} node;

// ���⿡ �ִ� �Լ��� �׷��� �����ϴ°� ����

// doubly circular linked list�� ���ο� ��带 �����ϴ� �Լ�
void dinsert1(nodePointer node, nodePointer newNode) {
	// newNode ���忡��
	newNode->llink = node;
	newNode->rlink = node->rlink;
	// ����� ���忡��
	node->rlink->llink = newNode;
	node->rlink = newNode;
}
// �򰥸���.. ���⼭�� ��尡 �׻� �ִٰ� �����ϴ� �ǰ� + ������ Ʋ��
void dinsert2(nodePointer node, nodePointer newNode) {
	//newNode���忡��
	newNode->llink = node;
	newNode->rlink = node->rlink;
	// ��������忡��
	node->rlink->llink = newNode;	// �̰� ���� �������! ��? �ƴϸ� rlink�� �̹� �ٲ�� �����ϱ� ������ �� ���� ���ݾ�!
	node->rlink = newNode;
}

// doubly circular linked list w/ header node�� ��带 �����ϴ� �Լ�
void ddelete1(nodePointer header, nodePointer deleted) {
	if (deleted == header) {
		printf("Deletion of header node : not permitted. \n");
	}
	else {
		deleted->llink->rlink = deleted->rlink;
		deleted->rlink->llink = deleted->llink;
		free(deleted);
	}
}
// ����
void ddelete2(nodePointer header, nodePointer ddelete) {
	if (ddelete == header) {
		fprintf(stderr, "�����带 ������ �� �����ϴ�!");
		exit(EXIT_FAILURE);
	}
	else {
		ddelete->llink->rlink = ddelete->rlink;
		ddelete->rlink->llink = ddelete->llink;
		free(ddelete);
	}
}