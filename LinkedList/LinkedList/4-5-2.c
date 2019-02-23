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

// circular linked list�� �տ� ��带 �����ϴ� �Լ�
void insertFront1(listPointer* last, listPointer node) {
	if (!(*last)) {	// ���� ����� ���
		(*last) = node;
		node->link = node;
	}
	else {	// ���� ��尡 �ƴ� ���
		node = (*last)->link;
		(*last)->link = node;
	}
}
// Ʋ��. �׻� ���尡 ���� ��츦 ��������.
void insertFront2(listPointer* last, listPointer node) {
	if (!(*last)) {	// ������ �ϰ��
		(*last) = node;
		node->link = node;
	}
	else {	// �����尡 �ƴ� ��� > ���� ������ �Ŷ� ����
		node = (*last)->link;
		(*last)->link = node;
	}
}

// circular linked list�� ���̸� ����ϴ� �Լ�
int length1(listPointer last) {
	listPointer temp;	// traverse�ϱ� ���� ���� ������
	temp = last;
	int count = 0;
	do {
		count++;
		temp = temp->link;
	} while (temp != last);

	return count;
}
// Ʋ��
// do while ����
int length2(listPointer last) {
	int count = 0;
	listPointer temp = last;

	do {
		count++;
		temp = temp->link;
	} while (temp != last);

	return count;
}