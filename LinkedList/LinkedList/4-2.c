#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if (!((ptr) = malloc(str))) {\
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

typedef struct listNode* listPointer;
typedef struct listNode{	// �׻� ����������!
	int data;
	listPointer link;
} listNode;

// ��尡 2���� linked list�� ����� ù ��° ����� �ּҰ��� ��ȯ�ϴ� �Լ�
listPointer create1(void) {
	// linked list�� ����Ű�� first�� second ����Ʈ������ ����
	listPointer first = NULL;	// Ȥ�� �𸣴� NULL�� �ʱ�ȭ����!
	listPointer second = NULL;	// Ȥ�� �𸣴� NULL�� �ʱ�ȭ����!

	// ���� �Ҵ��ؼ� ��忡 ����(������ �Ƕ����� ����� ����)
	MALLOC(first, sizeof(listNode));
	MALLOC(second, sizeof(listNode));

	// �������ʵ�� ��ũ�ʵ� �˾Ƽ� �ʱ�ȭ
	first->data = 5;
	first->link = second;
	second->data = 10;
	second->link = NULL;

	// linked list�� �ּ� ��ȯ
	return first;
}
// ����
listPointer create2(void) {
	listPointer first;
	listPointer second;

	MALLOC(first, sizeof(listNode));
	MALLOC(second, sizeof(listNode));

	first->data = 10;
	first->link = second;
	second->data = 20;
	second->link = NULL;
	
	return first;
}


// ����Ʈ�� ��� x �ڿ� ��带 �����ϴ� �Լ�
void insert(listPointer* first, listPointer x) {	// ���������� : ���� first�� update�� �ʿ� -> header����� �ʿ伺(����)
	// ���� �߰��� ��� ����
	listPointer temp;
	MALLOC(temp, sizeof(listNode));
	temp->data = 50;

	// �߰� �۾�
	if (*first) { // ���尡 �ƴ� ���
		temp->link = x->link; // ���� �ɾ��ְ�
		x->link = temp;
	}
	else { // ������ ���
		temp->link = NULL;
		*first = temp;	// ����!!
	}
}
// ����
void insert2(listPointer *first, listPointer x) {
	// ������ ���ο� ��带 ����
	listPointer temp;
	MALLOC(temp, sizeof(listNode));

	// ���� / ���尡 �ƴ� ��� 
	if (*first) {	// �� ��尡 �ƴ� ���
		temp->link = x->link;
		x->link = temp;
	}
	else {	// �� ����� ���
		(*first) = temp;
		temp->link = NULL;
	}
}

// trail�� ����Ű�� ���� ���(x�� ����Ű�� ���) ����
// trail�� �ʿ��� ���� : x�� �������� ������ ��带 ��� �ϵ� �ؾ��ؼ�
// �� �� �� �𸣸� link�� ���� �� ���ݾ�
void delete1(listPointer* first, listPointer trail, listPointer x) {	// ���������� : ���� first�� update�ʿ� -> header����� �߿伺(����)
	if (trail) {	// �����尡 �ִ� ���
		trail->link = x->link;
	}
	else {	// �����尡 ���� ���
		*first = (*first)->link;	
		// ��ȣ ���� ���� ��!
		// �����尡 ������ first�� update��������Ѵ�.
	}
	free(x);
}
// �ָ�(�ٽ� ����)
void delete2(listPointer* first, listPointer trail, listPointer x) {
	if (trail) {
		trail->link = x->link;
	}
	else {
		(*first) = (*first)->link;
	}
	free(x);
}

// ����Ʈ�� �ִ� ������ �ʵ带 ����� ���� �Լ�
void printList1(listPointer first) {
	for (; first; first = first->link) {	//first�� ���带 ����Ű�� ���� ������
		printf("%4d", first->data);
	}
}
// ����
void printList2(listPointer first) {
	for (; first; first = first->link) {
		printf("%5d", first->data);
	}
}