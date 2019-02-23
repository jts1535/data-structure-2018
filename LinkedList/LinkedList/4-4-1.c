// �ܹ��� linked list
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))) {\
		fprintf(stderr,"Insufficient Memory"); \
		exit(EXIT_FAILURE); \
	}
#define COMPARE(a, b) (a>b)?1:((a==b)?0:-1)

typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
} polyNode;
polyPointer a, b;


// a�� b�� �ջ�� ���׽��� ��ȯ�ϴ� �Լ�
polyPointer padd1(polyPointer a, polyPointer b) {
	polyPointer c;	// ���ο� ���׽� ��� ������
	polyPointer rear;	// c�� ������ ���� ����Ű�� ��� ������
	polyPointer temp;	// header ��带 �����ϱ� ���� �ӽ� ������
	// header��� ����
	MALLOC(rear, sizeof(polyNode));
	c = rear;
	int sum;
	while (a && b) {
		switch (COMPARE(a->expon, b->expon)) {
		case 1:
			attach1(a->coef, a->expon, &rear);
			a = a->link;
			break;
		case 0:
			sum = a->coef + b->coef;
			if (sum) {
				attach1(sum, a->expon, &rear);
			}
			a = a->link;
			b = b->link;
			break;
		case -1:
			attach1(b->coef, b->expon, &rear);
			b = b->link;
			break;
		}
	}
	for (; a; a = a->link) attach1(a->coef, a->expon, &rear);
	for (; b; b = b->link) attach1(b->coef, b->expon, &rear);
	rear->link = NULL;
	temp = c; c = c->link; free(temp);

	return c;
}
void attach2(int coef, int expon, polyPointer* rear) {
	polyPointer temp;
	MALLOC(temp, sizeof(polyNode));
	temp->coef = coef;
	temp->expon = expon;
	(*rear)->link = temp;
	(*rear) = temp;
}
// ��¦ �ٸ�. ��û Ʋ�� �� �ƴϰ� �׷��� �� ��!
polyPointer padd2(polyPointer a, polyPointer b) {
	polyPointer c;	// ���ο� ���׽��� ����Ű�� ���� ������
	polyPointer rear;	// ���ο� ���׽��� �� ��带 ����Ű�� ���� ������
	polyPointer temp;	// �����带 ���߿� free�ϱ� ���� �ӽ� ������
	int sum;

	// ���� ��¦ �ٸ�. �������� rear������ ��� �����߾�
	MALLOC(c, sizeof(polyNode));
	rear = c;
	while (a && b) {
		switch (COMPARE(a->expon, b->expon)) {
		case 1:
			attach2(a->coef, a->expon, &rear);
			a = a->link;
			break;
		case 0:
			sum = a->coef + b->coef;
			if (sum) {
				attach2(sum, a->expon, &rear);
			}
			a = a->link;
			b = b->link;
			break;
		case -1:
			attach2(b->coef, b->expon, &rear);
			b = b->link;
			break;
		}
	}

	for (; a; a = a->link) attach2(a->coef, a->expon, &rear);
	for (; b; b = b->link) attach2(b->coef, b->expon, &rear);
	
	// �̰� ���԰�
	rear->link = NULL;
	temp = c; c = c->link; free(temp);

	return c;
}
void attach2(int coef, int expon, polyPointer* rear) {
	polyPointer temp;
	MALLOC(temp, sizeof(polyNode));

	temp->coef = coef; temp->expon = expon; // temp->link = NULL; �ص� �ǰ� ���ص� �ǰ� �� ����� ��¥�� ���߿�  NULL���ִϱ�

	(*rear)->link = temp;
	(*rear) = temp;
}

// ���׽��� �����ϴ� �Լ�
void erase1(polyPointer* ptr) {
	polyPointer temp;
	while (*ptr) {
		temp = (*ptr);
		(*ptr) = (*ptr)->link;
		free(temp);
	}
}
// Ʋ��
void erase2(polyPointer *ptr) {
	polyPointer temp; // ������ ���� ������
	
	// ptr�� NULL�� �ƴ� ������
	while (*ptr) {
		// temp�� ������ ��忡 ������ �ϰ�
		// ptr�� �� ���� ��带 ����Ű��
		// temp�� ����
		// �̰� ptr�� ���׽� ���� ��忡 ������ ������ �ϴ� ����
		temp = (*ptr);
		(*ptr) = (*ptr)->link;
		free(temp);
	}

}
