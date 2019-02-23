// simple linked list
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if(!((p) = malloc(str))) {\
		fprintf(stderr, "Insufficient Memory");\
		exit(EXIT_FAILURE);\
	}

// 노드에 관한 선언
typedef struct listNode* listPointer;
typedef struct listNode {
	char data;
	listPointer link;
} listNode;

// 단순 linked list를 역순으로 만드는 함수
listPointer invert1(listPointer lead) {
	listPointer middle, trail;
	middle = NULL;
	while (lead) {
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}

	return middle;
}
// 순서가 다르면 안돼!!! 틀렸어!!!! 먼저 trail이 middle걸 가리키도록 해야해
// 뒤에서 부터 보자!
listPointer invert2(listPointer lead) {
	listPointer middle, trail;
	middle = NULL;

	while (lead) {
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}

	return middle;
}

// 단순 linked list 2개를 연결하는 함수
listPointer concatenate1(listPointer ptr1, listPointer ptr2) {
	listPointer temp;

	if (!ptr1) return ptr2;
	if (!ptr2) return ptr1;

	for (temp = ptr1; temp->link; temp = temp->link);

	temp->link = ptr2;

	return ptr1;
}
// 틀림. 임시 포인터를 두어야 한다.
listPointer concatemate2(listPointer ptr1, listPointer ptr2) {
	listPointer temp;
	
	if (!ptr1) return ptr2;
	if (!ptr2) return ptr1;

	for (temp = ptr1; temp->link; temp = temp->link);

	temp->link = ptr2;

	// 반환할 때 첫 노드로 반환해주기 위해서는 임시포인터가 필요
	// 그니까 항상 생각해야할게 traverse는 원본이 움직여야할 일이 있으면
	// 원본을 지켜주기 위해서 임시포인터가 필요
	return ptr1;
}
