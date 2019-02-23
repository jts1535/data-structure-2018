#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))){ \
		fprintf(stderr, "Insufficient Memory"); \
		exit(EXIT_FAILURE); \
	}

// linked stack에 관한 선언
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



// i번째 스택에 item 삽입하는 함수
void push1(int i, element item) {
	// 추가할 노드 생성
	stackPointer temp;
	MALLOC(temp, sizeof(stack));
	// 노드 필드 초기화
	temp->data = item;
	temp->link = top[i];	// 쌓여있던 것에다 걸고 나서
	// top이 temp를 가리키도록 한다
	top[i] = temp;	
}
// 맞음
void push2(int i, element item) {
	//삽입할 노드 생성
	stackPointer temp;
	MALLOC(temp, sizeof(stack));

	temp->data = item;
	temp->link = top[i];

	top[i] = temp;
}

// i번째 스택으로 부터 top원소 삭제하는 함수
element pop1(int i) {
	// top에 있는 원소에 접근할 수 있는 임시 포인터 선언
	stackPointer temp = top[i];
	element item;
	// temp가 가리키는 노드가 없는 지 확인 = 스택이 비었는지 확인
	if (!temp) {
		stackEmpty();
	}
	// top에 있는 원소 저장
	item = temp->data;
	top[i] = temp->link;
	// 없애자
	free(temp);
	return item;
}
// 맞음
element pop2(int i) {
	stackPointer temp;
	element item;
	
	// 이거 빠지면 안돼!
	if (!temp) {
		stackEmpty();
	}

	temp = top[i];
	item = top[i]->data;

	top[i] = top[i]->link;
	free(temp);

	return item;
}


// 임시용    
void stackEmpty() {
}	