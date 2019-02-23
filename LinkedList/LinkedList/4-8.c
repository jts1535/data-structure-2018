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

// 여기에 있는 함수는 그려서 이해하는게 좋음

// doubly circular linked list에 새로운 노드를 삽입하는 함수
void dinsert1(nodePointer node, nodePointer newNode) {
	// newNode 입장에서
	newNode->llink = node;
	newNode->rlink = node->rlink;
	// 상대노드 입장에서
	node->rlink->llink = newNode;
	node->rlink = newNode;
}
// 헷갈린다.. 여기서는 노드가 항상 있다고 생각하는 건가 + 순서도 틀림
void dinsert2(nodePointer node, nodePointer newNode) {
	//newNode입장에서
	newNode->llink = node;
	newNode->rlink = node->rlink;
	// 상대노드입장에서
	node->rlink->llink = newNode;	// 이걸 먼저 해줘야해! 왜? 아니면 rlink는 이미 바뀌어 버리니까 접근을 할 수가 없잖아!
	node->rlink = newNode;
}

// doubly circular linked list w/ header node에 노드를 삭제하는 함수
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
// 맞음
void ddelete2(nodePointer header, nodePointer ddelete) {
	if (ddelete == header) {
		fprintf(stderr, "헤더노드를 삭제할 수 없습니다!");
		exit(EXIT_FAILURE);
	}
	else {
		ddelete->llink->rlink = ddelete->rlink;
		ddelete->rlink->llink = ddelete->llink;
		free(ddelete);
	}
}