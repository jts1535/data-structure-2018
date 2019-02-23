#include <stdio.h>
#include <stdlib.h>
#define numRow 10
#define numCol 10
#define MAX_STACK_SIZE 100

typedef enum { N, NE, E, SE, S, SW, W, NW } direction;
typedef enum {false, true} boolean;

typedef struct {
	short int vert;
	short int horiz;
}offset;

typedef struct {
	int row;
	int col;
	int dir;
}element;
element stack[MAX_STACK_SIZE];
int top = -1;

int maze[numRow + 2][numCol + 2];

int exitRow = 10, exitCol = 10;

// 미로에 관한 함수
void path(void);
void setUpMaze();
void setOffset(offset *move);
void printMaze();

// 스택에 관한 함수
void stackPush(element item);
boolean stackEmpty();
boolean stackFull();
element stackPop();