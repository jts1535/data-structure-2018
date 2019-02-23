#include "header.h"

int main() {
	treePointer first = CreateNode('a');

	while (1) {
		// 사용자로부터 입력받음
		char str[6];
		printf(">>");
		scanf_s("%s", str, sizeof(str));

		// a - F - b 와 같은 형식
		if ((str[2] == 'F') || (str[2] == 'M')) {
			// 앞의 것이 노드에 없는 경우
			if (!ExistNode(first, str[0])) {
				// 새로 생성한 뒤 삽입하기
				treePointer second = CreateNode(str[0]);
				treePointer third = ExistNodeLocation(first, str[4]);
				if (str[2] == 'F') second->father = third;
				else second->mother = third;
				first = second; // root노드 update
				PreOrderTraverse(first);
				printf("\n");
			}
			else { // 앞의 것이 노드에 있는 경우
				   // 찾아서 
				treePointer second = ExistNodeLocation(first, str[0]);
				treePointer third = CreateNode(str[4]);
				// 연결하기
				if (str[2] == 'F') second->father = third;
				else second->mother = third;
				PreOrderTraverse(first);
				printf("\n");
			}
		}
		// a - ? - b 형식일 경우
		else if (str[2] == '?') {
			treePointer parent = ExistNodeLocation(first, str[0]);
			pathFinding(parent, str[4]);
			for (int i = 0; i < top + 1; i++) {
				printf("%c-%c-", stack[i].node->name, stack[i].dir);
			}
			printf("%c\n", str[4]);
			stackFlush();
		}
		else if ((str[0] == 'E') && (str[1] == 'n') && (str[2] == 'd')) {
			printf("프로그램이 종료됩니다.\n");
			break;
		}
		else {
			printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
		}
	}
}

// 트리와 관련된 함수들
treePointer CreateNode(char nData) {
	treePointer newNode = (treePointer)malloc(sizeof(node));
	newNode->mother = NULL;
	newNode->father = NULL;
	newNode->name = nData;

	return newNode;
}

int ExistNode(treePointer ptr, char nData) {
	if (!ptr) return FALSE;
	if (ptr->name == nData) return TRUE;
	if (ExistNode(ptr->father, nData)) return TRUE;
	return ExistNode(ptr->mother, nData);
}

treePointer ExistNodeLocation(treePointer ptr, char nData) {
	if (!ptr) return NULL;
	if (ptr->name == nData) return ptr;
	treePointer p = ExistNodeLocation(ptr->father, nData);
	if (p) return p;
	return ExistNodeLocation(ptr->mother, nData);
}

void PreOrderTraverse(treePointer ptr) {
	if (ptr) {
		printf("%c", ptr->name);
		PreOrderTraverse(ptr->father);
		PreOrderTraverse(ptr->mother);
	}
}

void pathFinding(treePointer ptr, char nData) {
	element e;
	for (; ; ) {
		for (; ptr; ptr = ptr->father) {
			if (ptr->name == nData) return;
			e.node = ptr; e.dir = 'F'; stackPush(e);
		}
		e = stackPop();
		while (e.dir == 'M') e = stackPop();
		e.dir = 'M'; stackPush(e);
		ptr = e.node->mother;
	}
}

// 스택 관련한 함수
void stackPush(element item) {
	if (stackFull()) {
		printf("stack full\n");
	}
	stack[++top] = item;
}

element stackPop() {
	if (stackEmpty()) {
		printf("stack empty\n");
	}
	return stack[top--];
}

int stackEmpty() {
	if (top < 0) {
		return TRUE;
	}
	return FALSE;
}

int stackFull() {
	if (top >= MAX_STACK_SIZE) {
		return TRUE;
	}
	return FALSE;
}

void stackFlush() {
	while (!(top == -1)) stackPop();
}