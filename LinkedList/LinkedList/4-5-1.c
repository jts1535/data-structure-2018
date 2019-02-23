// simple linked list
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, str) \
	if(!((p) = malloc(str))) {\
		fprintf(stderr, "Insufficient Memory");\
		exit(EXIT_FAILURE);\
	}

// ��忡 ���� ����
typedef struct listNode* listPointer;
typedef struct listNode {
	char data;
	listPointer link;
} listNode;

// �ܼ� linked list�� �������� ����� �Լ�
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
// ������ �ٸ��� �ȵ�!!! Ʋ�Ⱦ�!!!! ���� trail�� middle�� ����Ű���� �ؾ���
// �ڿ��� ���� ����!
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

// �ܼ� linked list 2���� �����ϴ� �Լ�
listPointer concatenate1(listPointer ptr1, listPointer ptr2) {
	listPointer temp;

	if (!ptr1) return ptr2;
	if (!ptr2) return ptr1;

	for (temp = ptr1; temp->link; temp = temp->link);

	temp->link = ptr2;

	return ptr1;
}
// Ʋ��. �ӽ� �����͸� �ξ�� �Ѵ�.
listPointer concatemate2(listPointer ptr1, listPointer ptr2) {
	listPointer temp;
	
	if (!ptr1) return ptr2;
	if (!ptr2) return ptr1;

	for (temp = ptr1; temp->link; temp = temp->link);

	temp->link = ptr2;

	// ��ȯ�� �� ù ���� ��ȯ���ֱ� ���ؼ��� �ӽ������Ͱ� �ʿ�
	// �״ϱ� �׻� �����ؾ��Ұ� traverse�� ������ ���������� ���� ������
	// ������ �����ֱ� ���ؼ� �ӽ������Ͱ� �ʿ�
	return ptr1;
}
