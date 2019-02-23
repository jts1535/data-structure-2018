#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))){ \
		fprintf(stderr, "Insufficient Memory"); \
		exit(EXIT_FAILURE); \
	}

// linked stack�� ���� ����
#define MAX_STACK 10
typedef struct element {
	int key
} element;
typedef struct stack* stackPointer;
typedef struct stack {
	element data;
	stackPointer link;
} stack;
stackPointer top[MAX_STACK];



// i��° ���ÿ� item �����ϴ� �Լ�
void push1(int i, element item) {
	// �߰��� ��� ����
	stackPointer temp;
	MALLOC(temp, sizeof(stack));
	// ��� �ʵ� �ʱ�ȭ
	temp->data = item;
	temp->link = top[i];	// �׿��ִ� �Ϳ��� �ɰ� ����
	// top�� temp�� ����Ű���� �Ѵ�
	top[i] = temp;	
}
// ����
void push2(int i, element item) {
	//������ ��� ����
	stackPointer temp;
	MALLOC(temp, sizeof(stack));

	temp->data = item;
	temp->link = top[i];

	top[i] = temp;
}

// i��° �������� ���� top���� �����ϴ� �Լ�
element pop1(int i) {
	// top�� �ִ� ���ҿ� ������ �� �ִ� �ӽ� ������ ����
	stackPointer temp = top[i];
	element item;
	// temp�� ����Ű�� ��尡 ���� �� Ȯ�� = ������ ������� Ȯ��
	if (!temp) {
		stackEmpty();
	}
	// top�� �ִ� ���� ����
	item = temp->data;
	top[i] = temp->link;
	// ������
	free(temp);
	return item;
}
// ����
element pop2(int i) {
	stackPointer temp;
	element item;
	
	// �̰� ������ �ȵ�!
	if (!temp) {
		stackEmpty();
	}

	temp = top[i];
	item = top[i]->data;

	top[i] = top[i]->link;
	free(temp);

	return item;
}


// �ӽÿ�    
void stackEmpty() {
}	