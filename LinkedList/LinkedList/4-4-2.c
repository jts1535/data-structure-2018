// 단방향 circular linked list w/ header node
#include <stdio.h>
#include <stdlib.h>
#define COMPARE(a, b) (a>b)?1:((a==b)?0:-1)
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))){ \
		fprintf(stderr, "Insufficient Memory");\
		exit(EXIT_FAILURE);\
	}
enum { FALSE, TRUE };

// 다항식 노드에 관한 선언
typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
} polyNode;
polyPointer a, b;

// 가용노드에 관한 선언
polyPointer avail = NULL;

// 가용노드에서 노드를 가지고 오는 함수
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
// 한가지 틀림. 가용노드 하나 가져다 쓰면 avail이 다른 가용노드 쓰도록 해야지. 
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

// 가용노드에 노드를 되돌려주는 함수
void retNode1(polyPointer node) {
	node->link = avail;
	avail = node;
}
// 맞음
void retNode2(polyPointer node) {
	node->link = avail;
	avail = node;
}

// 다항식을 가용노드에 돌러놓는 함수(O(1))
// cicular linked list이다!
void cerase1(polyPointer* last) {
	polyPointer temp;
	if (*last) {
		temp = (*last)->link;
		(*last)->link = avail;
		avail = temp;
		(*last) = NULL;
	}
}
// 틀림
void cerase2(polyPointer* last) {
	// 원본은 그대로 두고 접근을 하기 위한 포인터를 따로 둔다
	polyPointer temp;
	// 만약 노드가 있다면
	if (*last) {
		// temp의 last의 다음 노드 즉, 첫 노드를 가리키고도록 하고
		temp = (*last)->link;
		// 끝 노드를 avail이 가리키는 노드에 걸고
		// avail은 첫 노드에 걸어
		(*last)->link = avail;
		avail = temp;
		// 노드가 다 빠져나갔으므로 last를 안전하게 NULL을 가리키도록 한다.
		(*last) = NULL;
	}
}

// 두 다항식(circular + header node)의 덧셈을 하는 함수
polyPointer cpadd1(polyPointer a, polyPointer b){
	polyPointer startA;	// 한바퀴를 돌았는지에 대한 지표
	polyPointer  c;	// 다항식 덧셈의 결과를 가리키는 포인터
	polyPointer lastC;	// circular이므로 마지막 노드와 헤더 노드를 가리키기 위한 지표
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
// 헤더노드가 존재한다!!!!!
// 틀림. do while을 사용한다
// 가용노드 사용한다
// 헤더노드가 있으므로 앞으로 옮겨야 한다.
polyPointer cpadd2(polyPointer a, polyPointer b) {
	polyPointer c;	// 새로운 다항식을 가리키는 포인터
	polyPointer startA;	// 나중에 나머지 거 할 때 필요
	polyPointer lastC;	// c의 마지막 노드를 가리키는 포인터
	int sum;
	int done = FALSE;

	// 헤더노드가 있으므로 뒤로 한칸씩 이동해야 한다.
	startA = a;
	a = a->link; b = b->link;

	// 헤더 노드가 있으므로 -1로 초기화시켜주고
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
// 맞음
void attach2(int coef, int expon, polyPointer* rear) {
	polyPointer temp;
	MALLOC(temp, sizeof(polyNode));

	temp->coef = coef; temp->expon = expon;
	(*rear)->link = temp;
	(*rear) = temp;
}