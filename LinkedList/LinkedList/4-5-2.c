// circular linked list
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))) {\
		fprintf(stderr, "Insufficient Memory"); \
		exit(EXIT_FAILURE); \
	}

typedef struct listNode* listPointer;
typedef struct listNode {
	char data;
	listPointer link;
} listNode;

// circular linked list의 앞에 노드를 삽입하는 함수
void insertFront1(listPointer* last, listPointer node) {
	if (!(*last)) {	// 공백 노드일 경우
		(*last) = node;
		node->link = node;
	}
	else {	// 공백 노드가 아닐 경우
		node = (*last)->link;
		(*last)->link = node;
	}
}
// 틀림. 항상 빈노드가 있을 경우를 생각하자.
void insertFront2(listPointer* last, listPointer node) {
	if (!(*last)) {	// 공백노드 일경우
		(*last) = node;
		node->link = node;
	}
	else {	// 공백노드가 아닐 경우 > 내가 생각한 거랑 같은
		node = (*last)->link;
		(*last)->link = node;
	}
}

// circular linked list의 길이를 계산하는 함수
int length1(listPointer last) {
	listPointer temp;	// traverse하기 위한 접근 포인터
	temp = last;
	int count = 0;
	do {
		count++;
		temp = temp->link;
	} while (temp != last);

	return count;
}
// 틀림
// do while 쓴다
int length2(listPointer last) {
	int count = 0;
	listPointer temp = last;

	do {
		count++;
		temp = temp->link;
	} while (temp != last);

	return count;
}