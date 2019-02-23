#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main(void) {
	setUpMaze();
	path();
	printMaze();
}

void path(void) {
	int row, col, nextRow, nextCol, dir;
	boolean found = false;

	// move의 방향 설정하기
	offset move[8];
	setOffset(move);

	// 시간을 시드로 하여 출구의 위치를 랜덤으로 바꿔주기
	srand(time(NULL));
	while (maze[exitRow][exitCol]) {
		exitRow = rand() % 10 + 1;
		exitCol = rand() % 10 + 1;
	}

	element position;
	stack->row = 1;
	stack->col = 1;
	stack->dir = 1;
	top++;
	
	while (top > -1 && !found) {
		position = stackPop();
		row = position.row;
		col = position.col;
		dir = position.dir;
		while (dir < 8 && !found) {
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;

			// 주변에 출구가 있는지 검사하여 돌아가지 말고 바로 출구로 갈 수 있도록 함
			if (examineNearExit(row, col, exitRow, exitCol)) {
				maze[row][col] = 2;
				found = true;
			}
			// mark[][]배열을 사용하지 않고 maze[row][col] = 2로 바꾸어 이미 간 길을 표시함
			else if (!maze[nextRow][nextCol]) {
				position.row = row;
				position.col = col;
				position.dir = dir;
				stackPush(position);
				maze[row][col] = 2;
				row = nextRow;
				col = nextCol;
				dir = 0;
			}
			else {
				dir++;
				if (dir == 8) maze[row][col] = 3;
				// 주변에 하나도 0이 없을 때는 3으로 바꾸고 나오도록 하고
				// 주변에 0이 하나라도 있다면 다시 방향을 난수로 지정한다.
			}
		}
	}

	// 길 출력
	if (found) {
		printf("The path is \n");
		for (int i = 0; i <= top; i++) {
			printf("(%d, %d) ", stack[i].row, stack[i].col);
		}
		printf("(%d, %d) ", row, col);
		printf("(%d, %d) \n", exitRow, exitCol);
	}
	else printf("The maze does not have a path.\n");

}

void setUpMaze() {

	srand(time(NULL));
	short int maze0[numRow][numCol] = { 0 };

	//난수 지정
	for (int i = 0; i < numRow; i++) {
		for (int j = 0; j < numCol; j++) {
			maze0[i][j] = rand() % 2;
		}
	}

	maze0[0][0] = 0;

	// 울타리 생성
	for (int i = 0; i < numCol + 2; i++) {
		maze[0][i] = 1;
		maze[numRow + 1][i] = 1;
	}
	for (int i = 0; i < numRow + 2; i++) {
		maze[i][0] = 1;
		maze[i][numCol + 1] = 1;
	}

	// 위의 미로요소로 배열 초기화
	for (int i = 1; i < numRow + 1; i++) {
		for (int j = 1; j < numCol + 1; j++) {
			maze[i][j] = maze0[i - 1][j - 1];
		}
	}
}
void setOffset(offset* move) {
	move[N].vert = -1;	move[N].horiz = 0;
	move[NE].vert = -1;	move[NE].horiz = 1;
	move[E].vert = 0;	move[E].horiz = 1;
	move[SE].vert = 1;	move[SE].horiz = 0;
	move[S].vert = 1;	move[S].horiz = 0;
	move[SW].vert = 1;	move[SW].horiz = -1;
	move[W].vert = 0;	move[W].horiz = -1;
	move[NW].vert = -1; move[NW].horiz = -1;
}
// 미로를 출력할 때 보기 편하도록 네모를 이용해서 출력
void printMaze() {
	for (int i = 1; i < numRow + 1; i++) {
		for (int j = 1; j < numCol + 1; j++) {
			if (i == exitRow && j == exitCol) { printf("☆"); }
			else if (maze[i][j] == 0) { printf("□"); }	// 안간 곳
			else if (maze[i][j] == 1) { printf("■"); } // 막혀있는 곳
			else if (maze[i][j] == 2) { printf("▨"); } // 간 곳
			else { printf("▦"); } // 방향이 없어
		}
		printf("\n");
	}
}
boolean examineNearExit(int row, int col, int exitRow, int exittCol) {
	double distance = (exitRow - row)*(exitRow - row) + (exitCol - col)*(exitCol - col);
	if (distance <= 2) {
		return true;
	} return false;
}

// 스택 관련한 함수
void stackPush(element item) {
	if (stackFull()) {
		printf("stack full\n");
	}
	stack[++top] = item;
}
boolean stackEmpty() {
	if (top < 0) {
		return true;
	}
	return false;
}
boolean stackFull() {
	if (top >= MAX_STACK_SIZE) {
		return true;
	}
	return false;
}
element stackPop() {
	if (stackEmpty()) {
		printf("stack empty\n");
	}
	return stack[top--];
}