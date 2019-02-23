#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))){	\
		fprintf(stderr, "Insufficient Memory"); \
		exit(EXIT_FAILURE); \
	}

// linked queue에 관한 선언
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


// 큐 i의 뒤에 원소를 삽입하는 함수
void qadd1(int i, element item) {
	// 새로운 노드 생성
	queuePointer temp;
	MALLOC(temp, sizeof(queue));
	// 노드 초기화
	temp->data = item;
	temp->link = NULL;
	// 삽입하는 과정
	if (front[i]) {
		rear[i]-> link = temp;
		// rear[i] = temp;
	}
	else {
		front[i] = temp;
		rear[i] = temp;
	}
}
// 틀림
// 큐 i의 뒤에(rear뒤에) 원소를 삽입하는 함수
void qadd2(int i, element item) {
	// 새로운 노드 생성
	queuePointer temp;
	MALLOC(temp, sizeof(queue));

	temp->data = item;
	temp->link = NULL;
	// 여기서부터 틀림
	if (front[i]) {	// 빈노드가 아니라면
		rear[i]->link = temp;
	}
	else {
		front[i] = temp;
		rear[i] = temp;
	}
}


// 큐 i로부터 원소를 삭제하는 함수
element qdelete1(int i) {
	// 삭제할 노드를 가리키는 임시 포인터
	queuePointer temp = front[i];
	element item;
	if (!temp) {
		queueEmpty();
	}
	// 반환하므로 임시 저장
	item = temp->data;
	front[i] = temp->link;
	// 삭제
	free(temp);
	return item;
}
// 틀림
// 큐 i로부터 원소를 삭제하는 함수
element qdelete2(int i) {
	// 처읍부터 접근을 해야하고
	queuePointer temp = front[i];
	element item;

	// 일단 접근을 하고 나서 노드가 있는지 검사를 한다음에
	if (!temp) {
		queueEmpty();
	}

	// 노드가 있으면 다음과 같은 과정을 진행
	// 일단 element를 저장하고
	item = front[i]->data;

	// 삭제과정
	front[i] = front[i]->link;
	free(temp);

	return item;
}


// 임시함수
void queueEmpty() {
}