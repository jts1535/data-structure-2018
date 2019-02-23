#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))) {\
		fprintf(stderr, "Insufficient Memory"); \
		exit(EXIT_FAILURE); \
	}
enum {FALSE, TRUE};

// 그래프 노드에 관한 선언
short int visited[MAX_VERTICES];	// 그 노드에 방문했는지 여부
typedef struct node* nodePointer;
typedef struct node {
	int vertex;
	nodePointer link;
} node;
nodePointer graph[MAX_VERTICES];	// 그래프를 구현한 것(Adjacent list)

// 큐에 관한 선언
typedef struct queue* queuePointer;
typedef struct queue {
	int vertex;
	queuePointer link;
} queue;
queuePointer front, rear;
void addq(int);
int deleteq();

// 깊이 우선 탐색
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

// 너비 우선 탐색
// 레벨 탐색과 비슷
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