#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if (!((ptr) = malloc(str))) {\
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

typedef struct listNode* listPointer;
typedef struct listNode{	// 항상 통일해주자!
	int data;
	listPointer link;
} listNode;

// 노드가 2개인 linked list를 만들어 첫 번째 노드의 주소값을 반환하는 함수
listPointer create1(void) {
	// linked list를 가리키는 first와 second 리스트포인터 선언
	listPointer first = NULL;	// 혹시 모르니 NULL로 초기화하자!
	listPointer second = NULL;	// 혹시 모르니 NULL로 초기화하자!

	// 각각 할당해서 노드에 연결(접근할 건떡지를 만드는 것임)
	MALLOC(first, sizeof(listNode));
	MALLOC(second, sizeof(listNode));

	// 데이터필드와 링크필드 알아서 초기화
	first->data = 5;
	first->link = second;
	second->data = 10;
	second->link = NULL;

	// linked list의 주소 반환
	return first;
}
// 맞음
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


// 리스트의 노드 x 뒤에 노드를 삽입하는 함수
void insert(listPointer* first, listPointer x) {	// 이중포인터 : 실제 first의 update가 필요 -> header노드의 필요성(빈노드)
	// 새로 추가할 노드 생성
	listPointer temp;
	MALLOC(temp, sizeof(listNode));
	temp->data = 50;

	// 추가 작업
	if (*first) { // 빈노드가 아닌 경우
		temp->link = x->link; // 먼저 걸어주고
		x->link = temp;
	}
	else { // 빈노드인 경우
		temp->link = NULL;
		*first = temp;	// 꼭꼭!!
	}
}
// 맞음
void insert2(listPointer *first, listPointer x) {
	// 삽입할 새로운 노드를 생성
	listPointer temp;
	MALLOC(temp, sizeof(listNode));

	// 빈노드 / 빈노드가 아닐 경우 
	if (*first) {	// 빈 노드가 아닐 경우
		temp->link = x->link;
		x->link = temp;
	}
	else {	// 빈 노드일 경우
		(*first) = temp;
		temp->link = NULL;
	}
}

// trail이 가리키는 다음 노드(x가 가리키는 노드) 삭제
// trail이 필요한 이유 : x가 없어지고 나서의 노드를 어떻게 하든 해야해서
// 그 전 걸 모르면 link를 이을 수 없잖아
void delete1(listPointer* first, listPointer trail, listPointer x) {	// 이중포인터 : 실제 first의 update필요 -> header노드의 중요성(빈노드)
	if (trail) {	// 선행노드가 있는 경우
		trail->link = x->link;
	}
	else {	// 선행노드가 없는 경우
		*first = (*first)->link;	
		// 괄호 꼭꼭 써줄 것!
		// 선행노드가 없으면 first를 update시켜줘야한다.
	}
	free(x);
}
// 애매(다시 보기)
void delete2(listPointer* first, listPointer trail, listPointer x) {
	if (trail) {
		trail->link = x->link;
	}
	else {
		(*first) = (*first)->link;
	}
	free(x);
}

// 리스트에 있는 데이터 필드를 출력할 때의 함수
void printList1(listPointer first) {
	for (; first; first = first->link) {	//first가 빈노드를 가리키지 않을 때까지
		printf("%4d", first->data);
	}
}
// 맞음
void printList2(listPointer first) {
	for (; first; first = first->link) {
		printf("%5d", first->data);
	}
}