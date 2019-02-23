#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))){	\
		fprintf(stderr, "Insufficient Memory"); \
		exit(EXIT_FAILURE); \
	}

// linked queue�� ���� ����
#define MAX_QUEUE 10
typedef struct element {
	int key
} element;
typedef struct queue* queuePointer;
typedef struct queue {
	element data;
	queuePointer link;
} queue;
queuePointer front[MAX_QUEUE];
queuePointer rear[MAX_QUEUE];


// ť i�� �ڿ� ���Ҹ� �����ϴ� �Լ�
void qadd1(int i, element item) {
	// ���ο� ��� ����
	queuePointer temp;
	MALLOC(temp, sizeof(queue));
	// ��� �ʱ�ȭ
	temp->data = item;
	temp->link = NULL;
	// �����ϴ� ����
	if (front[i]) {
		rear[i]-> link = temp;
		// rear[i] = temp;
	}
	else {
		front[i] = temp;
		rear[i] = temp;
	}
}
// Ʋ��
// ť i�� �ڿ�(rear�ڿ�) ���Ҹ� �����ϴ� �Լ�
void qadd2(int i, element item) {
	// ���ο� ��� ����
	queuePointer temp;
	MALLOC(temp, sizeof(queue));

	temp->data = item;
	temp->link = NULL;
	// ���⼭���� Ʋ��
	if (front[i]) {	// ���尡 �ƴ϶��
		rear[i]->link = temp;
	}
	else {
		front[i] = temp;
		rear[i] = temp;
	}
}


// ť i�κ��� ���Ҹ� �����ϴ� �Լ�
element qdelete1(int i) {
	// ������ ��带 ����Ű�� �ӽ� ������
	queuePointer temp = front[i];
	element item;
	if (!temp) {
		queueEmpty();
	}
	// ��ȯ�ϹǷ� �ӽ� ����
	item = temp->data;
	front[i] = temp->link;
	// ����
	free(temp);
	return item;
}
// Ʋ��
// ť i�κ��� ���Ҹ� �����ϴ� �Լ�
element qdelete2(int i) {
	// ó������ ������ �ؾ��ϰ�
	queuePointer temp = front[i];
	element item;

	// �ϴ� ������ �ϰ� ���� ��尡 �ִ��� �˻縦 �Ѵ�����
	if (!temp) {
		queueEmpty();
	}

	// ��尡 ������ ������ ���� ������ ����
	// �ϴ� element�� �����ϰ�
	item = front[i]->data;

	// ��������
	front[i] = front[i]->link;
	free(temp);

	return item;
}


// �ӽ��Լ�
void queueEmpty() {
}