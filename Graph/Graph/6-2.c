#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))) {\
		fprintf(stderr, "Insufficient Memory"); \
		exit(EXIT_FAILURE); \
	}
enum {FALSE, TRUE};

// �׷��� ��忡 ���� ����
short int visited[MAX_VERTICES];	// �� ��忡 �湮�ߴ��� ����
typedef struct node* nodePointer;
typedef struct node {
	int vertex;
	nodePointer link;
} node;
nodePointer graph[MAX_VERTICES];	// �׷����� ������ ��(Adjacent list)

// ť�� ���� ����
typedef struct queue* queuePointer;
typedef struct queue {
	int vertex;
	queuePointer link;
} queue;
queuePointer front, rear;
void addq(int);
int deleteq();

// ���� �켱 Ž��
void dfs(int v) {
	nodePointer w;
	visited[v] = TRUE;
	printf("%5d", v);
	for (w = graph[v]; w; w = w->link) {
		if (!visited[w->vertex]) {
			dfs(w->vertex);
		}
	}
}

// �ʺ� �켱 Ž��
// ���� Ž���� ���
void bfs(int v) {
	nodePointer w;
	front = rear = NULL;
	printf("%5d", v);
	visited[v] = TRUE;
	addq(v);
	while (front) {
		v = deleteq();
		for (w = graph[v]; w; w = w->link) {
			if (!visited[w->vertex]) {
				printf("%5d", w->vertex);
				addq(w->vertex);
				visited[w->vertex] = TRUE;
			}
		}
	}
}