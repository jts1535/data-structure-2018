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

	// move�� ���� �����ϱ�
	offset move[8];
	setOffset(move);

	// �ð��� �õ�� �Ͽ� �ⱸ�� ��ġ�� �������� �ٲ��ֱ�
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

			// �ֺ��� �ⱸ�� �ִ��� �˻��Ͽ� ���ư��� ���� �ٷ� �ⱸ�� �� �� �ֵ��� ��
			if (examineNearExit(row, col, exitRow, exitCol)) {
				maze[row][col] = 2;
				found = true;
			}
			// mark[][]�迭�� ������� �ʰ� maze[row][col] = 2�� �ٲپ� �̹� �� ���� ǥ����
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
				// �ֺ��� �ϳ��� 0�� ���� ���� 3���� �ٲٰ� �������� �ϰ�
				// �ֺ��� 0�� �ϳ��� �ִٸ� �ٽ� ������ ������ �����Ѵ�.
			}
		}
	}

	// �� ���
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

	//���� ����
	for (int i = 0; i < numRow; i++) {
		for (int j = 0; j < numCol; j++) {
			maze0[i][j] = rand() % 2;
		}
	}

	maze0[0][0] = 0;

	// ��Ÿ�� ����
	for (int i = 0; i < numCol + 2; i++) {
		maze[0][i] = 1;
		maze[numRow + 1][i] = 1;
	}
	for (int i = 0; i < numRow + 2; i++) {
		maze[i][0] = 1;
		maze[i][numCol + 1] = 1;
	}

	// ���� �̷ο�ҷ� �迭 �ʱ�ȭ
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
// �̷θ� ����� �� ���� ���ϵ��� �׸� �̿��ؼ� ���
void printMaze() {
	for (int i = 1; i < numRow + 1; i++) {
		for (int j = 1; j < numCol + 1; j++) {
			if (i == exitRow && j == exitCol) { printf("��"); }
			else if (maze[i][j] == 0) { printf("��"); }	// �Ȱ� ��
			else if (maze[i][j] == 1) { printf("��"); } // �����ִ� ��
			else if (maze[i][j] == 2) { printf("��"); } // �� ��
			else { printf("��"); } // ������ ����
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

// ���� ������ �Լ�
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