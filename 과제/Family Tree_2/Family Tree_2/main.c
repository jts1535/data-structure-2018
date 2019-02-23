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
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			break;
		}
		printf("\n");
	}


	return 0;
}

// ����(father) ��� �߰�
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

// ������(mother) ��� �߰�
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

// Preorder�� traverse�Ͽ� ���
void Preorder(treePointer ptr)
{
	if (ptr)
	{
		printf("%c", ptr->name);
		Preorder(ptr->father);
		Preorder(ptr->mother);
	}
}

// ���ο� node ����
treePointer CreateNode()
{
	treePointer temp;
	temp = malloc(sizeof(node));
	temp->father = NULL; // NULL�� �ʱ�ȭ
	temp->mother = NULL; // NULL�� �ʱ�ȭ
	return temp;
}

// Ʈ���� ���� �����ϸ� �� ���� ������ �ִ� node�� �ּҰ��� ����
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

// ���赵 ���
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

// target�� subtree�� ���� root��带 ã�� �� ����� �ּҸ� ��ȯ
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