// �ִ� �Ÿ� ã�� �˰���
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
#define MALLOC(ptr, str) \
	if(!((ptr) = malloc(str))) {\
		fprintf(stderr, "Insufficient Memory"); \
		exit(EXIT_FAILURE); \
	}
enum { FALSE, TRUE };

// �׷��� ��忡 ���� ����
typedef struct node* nodePointer;
typedef struct node {
	int vertex;
	nodePointer link;
} node;

// �ʿ��� �迭 ����
int cost[MAX_VERTICES][MAX_VERTICES];
short int found[MAX_VERTICES];
int distance[MAX_VERTICES];

// �ִܰŸ��� ã���ִ� �Լ�
void shortestPath(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[]) {
	int i, u, w;
	for (i = 0; i < n; i++) {
		found[i] = FALSE;
		distance[i] = cost[v][i];
	}
	found[v] = TRUE;
	distance[v] = 0;
	for (i = 0; i < n - 2; i++) {
		u = choose(distance, n, found);
		found[u] = TRUE;
		for (w = 0; w < n; w++) {
			if (!found[w]) {
				if (distance[u] + cost[u][w] < distance[w]) {
					distance[w] = distance[u] + cost[u][w];
				}
			}
		}
	}
}

// FALSE�� vertex�߿��� ���� ����� vertex�� ã�Ƽ� ��ȯ�ϴ��Լ�
int choose(int distance[], int n, short int found[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}