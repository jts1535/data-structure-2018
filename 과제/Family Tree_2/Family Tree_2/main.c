#include "header.h"

int main(void)
{
	char str[10];
	printf(">>\n");

	while (1)
	{
		printf(">>");
		scanf_s("%s", str, sizeof(str));

		if (str[2] == 'F' || str[2] == 'f') {
			Father(str[0], str[4]);
			Preorder(root);
		}
		else if (str[2] == 'M' || str[2] == 'm') {
			Mother(str[0], str[4]);
			Preorder(root);
		}
		else if (str[2] == '?') {
			PathFinding(ExistNode(root, str[0]), str[4]);
		}
		else {
			printf("잘못 입력하셨습니다.\n");
			break;
		}
		printf("\n");
	}


	return 0;
}

// 왼쪽(father) 노드 추가
void Father(char parent, char child)
{
	int newRoot = FALSE;
	treePointer first = ExistNode(root, parent);
	if (!first)
	{
		newRoot = TRUE;
		first = CreateNode();
		first->name = parent;
	}
	treePointer second = ExistNode(root, child);
	if (!second)
	{
		second = CreateNode();
		second->name = child;
	}
	first->father = second;

	if (newRoot)
		root = first;
}

// 오른쪽(mother) 노드 추가
void Mother(char parent, char child)
{
	int newRoot = FALSE;
	treePointer first = ExistNode(root, parent);
	if (!first)
	{
		newRoot = TRUE;
		first = CreateNode();
		first->name = parent;
	}
	treePointer second = ExistNode(root, child);
	if (!second)
	{
		second = CreateNode();
		second->name = child;
	}
	first->mother = second;

	if (newRoot)
		root = first;
}

// Preorder로 traverse하여 출력
void Preorder(treePointer ptr)
{
	if (ptr)
	{
		printf("%c", ptr->name);
		Preorder(ptr->father);
		Preorder(ptr->mother);
	}
}

// 새로운 node 생성
treePointer CreateNode()
{
	treePointer temp;
	temp = malloc(sizeof(node));
	temp->father = NULL; // NULL로 초기화
	temp->mother = NULL; // NULL로 초기화
	return temp;
}

// 트리에 값이 존재하면 그 값을 가지고 있는 node의 주소값을 리턴
treePointer ExistNode(treePointer ptr, char nData)
{
	if (!ptr)
		return NULL;
	if (ptr->name == nData)
	{
		return ptr;
	}
	if (ExistNode(ptr->father, nData))
	{
		return ExistNode(ptr->father, nData);
	}
	return ExistNode(ptr->mother, nData);
}

// 가계도 출력
void PathFinding(treePointer first, char nData)
{
	if (first->name == nData)
	{
		printf("%c", first->name);
		return;
	}

	if (ExistNode(first->father, nData))
	{
		printf("%c-F-", first->name);
		PathFinding(first->father, nData);
	}
	else if (ExistNode(first->mother, nData))
	{
		printf("%c-M-", first->name);
		PathFinding(first->mother, nData);
	}
	else
	{
		PathFinding(ParentFinding(root, first->name, 'C'), nData);
	}
}

// target을 subtree로 갖는 root노드를 찾아 그 노드의 주소를 반환
treePointer ParentFinding(treePointer ptr, char target, char gender)
{
	if (!ptr)
		return NULL;

	if (ptr->father)
	{
		if (ptr->father->name == target)
		{
			printf("%c-%c-", ptr->father->name, gender);
			return ptr;
		}
	}
	if (ptr->mother)
	{
		if (ptr->mother->name == target)
		{
			printf("%c-%c-", ptr->mother->name, gender);
			return ptr;
		}

	}

	treePointer p;
	if (p = ParentFinding(ptr->father, target, 'S'))
	{
		return p;
	}

	return ParentFinding(ptr->mother, target, 'D');
}