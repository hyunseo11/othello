#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 6 
#define FALSE (0)
#define TRUE (1)

//�� ���� �� ��  
int totalPieceOnBoard = 4;
 
int checkPoint(int x, int y, int turn) {
	int checkPoint = checkInputPoint(x, y, turn);
	int checkClose = checkClosePiece(x, y, turn);
	int checkCross = checkCrossLinePiece(x, y, turn);
	
	return checkPoint && checkClose && checkCross;
}

int checkPoint(int x, int y, int turn) {
	if (x<0 || y<0 || x>BOARD_SIZE || y>BOARD_SIZE)
	return 0;
	int checkClose = checkClosePiece(x, y, turn);
	ubt checkCross = checkCrossLinePiece(x, y, turn);
	
	return checkClose && checkCross;
}

int initGameEndCheckFlag() {
	checkedTurn_player1 = 0;
	checkedTurn_player2 = 0;
}

int isGameEnd() {
    int endCheck = 0;
    
	// �������� �Ѱ��� ������  
	int checkedturned_player1 = 0;
    int checkedturned_player2 = 0;
    
	
	
	// ���� �÷��̾� ��� �����Ⱑ ������ ĭ�� ���� ���
	if (checkedturned_player1 && checkedturned_player2) {
		endCheck = 1;
		return endCheck;
	} 
	// ���� �ڸ��� ���� ��
	int remainBoard = BOARD_SIZE * BOARD_SIZE - totalPieceOnBoard;
	if (remainBoard == 0) {
		endCheck = 1;
		return endCheck;
	} 
	
	return endCheck;
}

int checkInputPoint(int x, int y, int turn) {
	int pointExist = 1;
	
	if(gameboard[x][y] != 0)
	   pointExist = 0;
	   
	return pointExist;
}

int checkClosePiece(int x, int y, int turn) {
	//��ó�� ������ ���� ���� ��
	int i, j;
	for (i=-1;i<2;i++) {
		for (j=-1;j<2;j++) {
			if (x+i>BOARD_SIZE || y+j>BOARD_SIZE || x+i <=0 || y+j <=0)
			   continue;
		    if (turn == 1){
		    	
			}
		    
		}
	} 
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	return 0;
}
