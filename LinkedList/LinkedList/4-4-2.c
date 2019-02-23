// �ܹ��� circular linked list w/ header node
#include <stdio.h>
#include <stdlib.h>
#define COMPARE(a, b) (a>b)?1:((a==b)?0:-1)
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))){ \
		fprintf(stderr, "Insufficient Memory");\
		exit(EXIT_FAILURE);\
	}
enum { FALSE, TRUE };

// ���׽� ��忡 ���� ����
typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
} polyNode;
polyPointer a, b;

// �����忡 ���� ����
polyPointer avail = NULL;

// �����忡�� ��带 ������ ���� �Լ�
polyPointer getNode1(void) {
	polyPointer node;
	if (avail) {
		node = avail;
		avail = avail->link;
	}
	else {
		MALLOC(node, sizeof(polyNode));
	}

	return node;
}
// �Ѱ��� Ʋ��. ������ �ϳ� ������ ���� avail�� �ٸ� ������ ������ �ؾ���. 
polyPointer getNode2(void) {
	polyPointer node;

	if (!avail) {
		node = avail;
		avail = avail->link;
	}
	else {
		MALLOC(node, sizeof(polyNode));
	}

	return node;
}

// �����忡 ��带 �ǵ����ִ� �Լ�
void retNode1(polyPointer node) {
	node->link = avail;
	avail = node;
}
// ����
void retNode2(polyPointer node) {
	node->link = avail;
	avail = node;
}

// ���׽��� �����忡 �������� �Լ�(O(1))
// cicular linked list�̴�!
void cerase1(polyPointer* last) {
	polyPointer temp;
	if (*last) {
		temp = (*last)->link;
		(*last)->link = avail;
		avail = temp;
		(*last) = NULL;
	}
}
// Ʋ��
void cerase2(polyPointer* last) {
	// ������ �״�� �ΰ� ������ �ϱ� ���� �����͸� ���� �д�
	polyPointer temp;
	// ���� ��尡 �ִٸ�
	if (*last) {
		// temp�� last�� ���� ��� ��, ù ��带 ����Ű���� �ϰ�
		temp = (*last)->link;
		// �� ��带 avail�� ����Ű�� ��忡 �ɰ�
		// avail�� ù ��忡 �ɾ�
		(*last)->link = avail;
		avail = temp;
		// ��尡 �� �����������Ƿ� last�� �����ϰ� NULL�� ����Ű���� �Ѵ�.
		(*last) = NULL;
	}
}

// �� ���׽�(circular + header node)�� ������ �ϴ� �Լ�
polyPointer cpadd1(polyPointer a, polyPointer b){
	polyPointer startA;	// �ѹ����� ���Ҵ����� ���� ��ǥ
	polyPointer  c;	// ���׽� ������ ����� ����Ű�� ������
	polyPointer lastC;	// circular�̹Ƿ� ������ ���� ��� ��带 ����Ű�� ���� ��ǥ
	int sum;
	int done = FALSE;
	
	startA = a;
	a = a->link; b = b->link;

	c = getNode(); c->expon = -1; lastC = c;
	
	do {
		switch (COMPARE(a->expon, b->expon)) {
		case 1:
			attach(a->coef, a->expon, &lastC);
			a = a->link;
			break;
		case 0:
			if (startA == a) done = TRUE;
			else {
				sum = a->coef + b->coef;
				if (sum) {
					attach(sum, a->expon, &lastC);
					a = a->link;
					b = b->link;
				}
				break;
			}
		case -1:
			attach(b->coef, b->expon, &lastC);
			b = b->link;
			break;
		}
	} while (!done);
	
	lastC->link = c;
	return c;
}
// �����尡 �����Ѵ�!!!!!
// Ʋ��. do while�� ����Ѵ�
// ������ ����Ѵ�
// �����尡 �����Ƿ� ������ �Űܾ� �Ѵ�.
polyPointer cpadd2(polyPointer a, polyPointer b) {
	polyPointer c;	// ���ο� ���׽��� ����Ű�� ������
	polyPointer startA;	// ���߿� ������ �� �� �� �ʿ�
	polyPointer lastC;	// c�� ������ ��带 ����Ű�� ������
	int sum;
	int done = FALSE;

	// �����尡 �����Ƿ� �ڷ� ��ĭ�� �̵��ؾ� �Ѵ�.
	startA = a;
	a = a->link; b = b->link;

	// ��� ��尡 �����Ƿ� -1�� �ʱ�ȭ�����ְ�
	c = getNode(); c->expon = -1; lastC = c;
	do {
		switch (COMPARE(a->expon, b->expon)) {
		case 1:
			attach(a->coef, a->expon, &lastC);
			a = a->link;
			break;
		case 0:
			if (startA == a) done = TRUE;
			sum = a->coef + b->coef;
			if (sum) {
				attach(sum, a->expon, &lastC);
			}
			a = a->link;
			b = b->link;
			break;
		case -1:
			attach(b->coef, b->expon, &lastC);
			b = b->link;
		}
	} while (!done);

	lastC->link = NULL;
	return c;
}

void attach1(int coef, int expon, polyPointer* rear) {
	polyPointer temp;
	MALLOC(temp, sizeof(polyPointer));
	temp->coef = coef;
	temp->expon = expon;
	(*rear)->link = temp;
	(*rear) = temp;
}
// ����
void attach2(int coef, int expon, polyPointer* rear) {
	polyPointer temp;
	MALLOC(temp, sizeof(polyNode));

	temp->coef = coef; temp->expon = expon;
	(*rear)->link = temp;
	(*rear) = temp;
}