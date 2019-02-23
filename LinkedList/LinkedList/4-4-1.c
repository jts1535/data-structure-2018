// 단방향 linked list
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


// a와 b가 합산된 다항식을 반환하는 함수
polyPointer padd1(polyPointer a, polyPointer b) {
	polyPointer c;	// 새로운 다항식 노드 포인터
	polyPointer rear;	// c의 마지막 항을 가리키는 노드 포인터
	polyPointer temp;	// header 노드를 삭제하기 위한 임시 포인터
	// header노드 생성
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
// 살짝 다름. 엄청 틀린 건 아니고 그래도 볼 것!
polyPointer padd2(polyPointer a, polyPointer b) {
	polyPointer c;	// 새로운 다항식을 가리키기 위한 포인터
	polyPointer rear;	// 새로운 다항식의 끝 노드를 가리키기 위한 포인터
	polyPointer temp;	// 헤더노드를 나중에 free하기 위한 임시 포인터
	int sum;

	// 여기 살짝 다름. 위에서는 rear가지고 노드 생성했어
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
	
	// 이거 빼먹고
	rear->link = NULL;
	temp = c; c = c->link; free(temp);

	return c;
}
void attach2(int coef, int expon, polyPointer* rear) {
	polyPointer temp;
	MALLOC(temp, sizeof(polyNode));

	temp->coef = coef; temp->expon = expon; // temp->link = NULL; 해도 되고 안해도 되고 내 맘대로 어짜피 나중에  NULL해주니까

	(*rear)->link = temp;
	(*rear) = temp;
}

// 다항식을 삭제하는 함수
void erase1(polyPointer* ptr) {
	polyPointer temp;
	while (*ptr) {
		temp = (*ptr);
		(*ptr) = (*ptr)->link;
		free(temp);
	}
}
// 틀림
void erase2(polyPointer *ptr) {
	polyPointer temp; // 접근을 위한 포인터
	
	// ptr이 NULL이 아닐 때까지
	while (*ptr) {
		// temp가 삭제할 노드에 접근을 하고
		// ptr는 그 다음 노드를 가리키고
		// temp는 삭제
		// 이걸 ptr가 다항식 끝의 노드에 도달할 때까지 하는 것임
		temp = (*ptr);
		(*ptr) = (*ptr)->link;
		free(temp);
	}

}
