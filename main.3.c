#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 6
#define POINTS_SIZE 8
#define POINT_UP 0
#define POINT_DOWN 1
#define POINT_LEFT 2
#define POINT_RIGHT 3
#define POINT_LEFTUP_CROSS 4
#define POINT_LEFTDOWN_CROSS 5
#define POINT_RIGHTUP_CROSS 6
#define POINT_RIGHTDOWN_CROSS 7
#define FALSE (0)
#define TRUE (1)

//빈공간 0, 흑색 1, 백색 2; 
int**gameboard;
//8방향의 값을 저장할 배열
//8방향은 위, 아래, 좌, 우, 좌상단, 좌하단, 우상단, 우하단
//음수라면 좌표가 없다는 뜻
int points_X[8];
int points_Y[8];
//총 돌의 개수
int totalPieceOnBoard = 4;
//player1이 선공 player2가 후공
int turn = 1;
// 연속으로 둘 곳이 없을 때 체크플래그
int checkedTurn_player1 = 0;
int checkedTurn_player2 = 0; 


void initOthello();
void printOthello();
void printGetPieces(int x, int y, int turn);
void printResult();
void initGameEndCheckFlag();
void initPoints();
int isGameEnd();
int checkPoint(int x, int y, int turn);
int checkPointStart(int x, int y, int turn);
int checkInputPoint(int x, int y, int turn);
int checkClosePiece(int x, int y, int turn);
int checkCrossLinePiece(int x, int y, int turn);
int checkPlaceOnBoard(int turn);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	printf("Play othello\n\n");
	
	
	init_othello();
	
	while (isGameEnd() == 0) {
		int x, y, i;
		print_othello();
		
		if(checkPlaceOnBoard(turn)) {
			//둘 곳이 없다면 
			scanf("%d %d", &x, &y);  //좌표 입력받기
			 if ((x<0 || x>BOARD_SIZE) || (y<0 || y>BOARD_SIZE)) {
			 	printf("돌을 놓을 곳이 없습니다. 다시 선택해주세요\n\n");
			 	continue;
			 }
			 if (checkPoint(x-i, y-i, turn)) { //둘 곳이 있는지 체크 
			     initGameEndCheckFlag();
				 totalPieceOnBoard++;
				 printfGetPieces(x-i, y-i, turn); 
			 }
			 else {
			 	printf("돌을 놓을 곳이 없습니다. 다시 선택해주세요\n\n");
			 	continue;
			 }
		}
		else {
			printf("skip %d turn \n\n", turn);
			// 둘 곳이 없다면 깃발을 올려두고 turned 
			if (turn == 1)
			    checkedTurn_player1 = 1;
			else
				checkedTurn_player2 = 1; 
		}
		
	    //turn은 넘어갑니다.  
		if(turn == 1)
		   turn = 2;
		else
		   turn = 1;
		
	}
	//결과를 프린트합니다. 
	printresult();

}

void init_othello() { //게임초기화
    int i, j;
    gameboard = (int**)malloc(sizeof(int*) * BOARD_SIZE);
    
	for (i=0;i<BOARD_SIZE;i++) {
		gameboard[i] = (int*)malloc(sizeof(int) * BOARD_SIZE);
	}
	for (i=0;i<BOARD_SIZE;i++) {
		for (j=0;j<BOARD_SIZE;j++) {
			gameboard[i][j] = 0;
		}
		
	}
  
    gameboard[(BOARD_SIZE / 2) -1][BOARD_SIZE / 2] = 1;
    gameboard[(BOARD_SIZE / 2) -1][(BOARD_SIZE / 2) -1] = 2;
    gameboard[BOARD_SIZE / 2][(BOARD_SIZE / 2) -1]  = 1;
    gameboard[BOARD_SIZE / 2][BOARD_SIZE / 2] = 2;
}

void printOthello() {
	printf("---------------------------------------------------\n");
	if (turn == 1)
	    printf("- BOARD ---%c turn ----------------------------------\n\n", 'o');
	else
	    printf("- BOARD ---%c tunr ----------------------------------\n\n", 'x');
	    
	//보드판 출력
	int i, j;
	for (i=0;i<BOARD_SIZE;i++) {
		for (j=0;j<BOARD_SIZE;j++) {
			switch (gameboard[j][i])
			{
				case 1:
					if (j==BOARD_SIZE -1)
					    printf(" %c", 'o');
					else
					    printf(" %c.", 'o');
					break;
				case 2:
					if (j==BOARD_SIZE -1)
					    printf(" %c", 'x');
					else
					    printf(" %c.", 'x');
					break;
					break;
				default:
					if (j == BOARD_SIZE -1)
					    printf(" %c", ' ');
					else 
					    printf(" %c.", ' ');
					break;
			}
		}
		printf("\n");
	} 
}
int checkPoint(int x, int y, int turn) {
	int checkPoint = checkInputPoint(x, y, turn);
	int checkClose = checkClosePiece(x, y, turn);
	int checkCross = checkCrossLinePiece(x, y, turn);
	
	return checkPoint && checkClose && checkCross;
}

int checkPointStart(int x, int y, int turn) {
	if (x<0 || y<0 || x>BOARD_SIZE || y>BOARD_SIZE)
	return 0;
	int checkClose = checkClosePiece(x, y, turn);
	int checkCross = checkCrossLinePiece(x, y, turn);
	
	return checkClose && checkCross;
}

void initGameEndCheckFlag() {
	checkedTurn_player1 = 0;
	checkedTurn_player2 = 0;
}

int isGameEnd() {
    int endCheck = 0;
    
	// 연속으로 둘곳이 없을때  
	int checkedturned_player1 = 0;
    int checkedturned_player2 = 0;
    
	
	
	// 양쪽 플레이어 모두 뒤집기가 가능한 칸이 없는 경우
	if (checkedturned_player1 && checkedturned_player2) {
		endCheck = 1;
		return endCheck;
	} 
	// 판의 자리가 없을 때
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
	//근처에 상대방의 돌이 있을 때
	int i, j;
	for (i=-1;i<2;i++) {
		for (j=-1;j<2;j++) {
			if (x+i>BOARD_SIZE || y+j>BOARD_SIZE || x+i <=0 || y+j <=0)
			   continue;
		    if (turn == 1){
		    	if (gameboard[x+i][y+j] == 2 && gameboard[x+i][y+j] != 0) {
		    		return 1;
				}
			}
		    else {
		    	if (gameboard[x+i][y+j] == 1 && gameboard[x+i][y+i] != 0) {
		    		return 1;
				}
			}
		}
	}
	return 0; 
}

int checkCrossLinePiece(int x, int y, int turn)  {
	//가로 세로 대각선의 8방향 돌을 체크하고 둘 수 있는지 return한다.
	//좌표지접에 대한 값은 전역변수에 저장
	//8방향은 위, 아래, 좌, 우, 좌상단, 좌하단, 우상단, 우하단이다.
	initPoints();  //8방향 초기화
	
	int returnTurn = 0;
	int i;
	
	for(i=1;y-i>=0;i++) {// 위 
	   if (i==1) {
	   	   if (gameboard[x][y-i] == turn)
	   	     break;
	   } 
	   else {
	   	   if (gameboard[x][y-i] == 0) {
	   		break;
		   }
		   else if (gameboard[x][y-i] == turn) {
			returnTurn = 1;
			points_X[0] = x;
			points_Y[0] = y-i;
			break;
		   }
	   }
	}
	
	for(i=1;y+i>=BOARD_SIZE;i++) {// 아래  
	   if (i==1) {
	   	   if (gameboard[x][y-i] == turn)
	   	     break;
	   } 
	   else {
	   	   if (gameboard[x][y-i] == 0) {
	   		break;
		   }
		   else if (gameboard[x][y-i] == turn) {
			returnTurn = 1;
			points_X[1] = x;
			points_Y[1] = y+i;
			break;
		   }
	   }
	}
	
	for(i=1;x-i>=0;i++) {// 좌  
	   if (i==1) {
	   	   if (gameboard[x-i][y] == turn)
	   	     break;
	   } 
	   else {
	   	   if (gameboard[x-i][y] == 0) {
	   		break;
		   }
		   else if (gameboard[x-i][y] == turn) {
			returnTurn = 1;
			points_X[2] = x-i;
			points_Y[2] = y;
			break;
		   }
	   }
	}
	
	for(i=1;y-i>=0;i++) {// 우  
	   if (i==1) {
	   	   if (gameboard[x+i][y] == turn)
	   	     break;
	   } 
	   else {
	   	   if (gameboard[x+i][y] == 0) {
	   		break;
		   }
		   else if (gameboard[x+i][y] == turn) {
			returnTurn = 1;
			points_X[3] = x+i;
			points_Y[3] = y;
			break;
		   }
	   }
	}
	
	//대각선
	while (x-i>=0 && y-i>=0) { // 좌상단  
		if (i==1) {
			if (gameboard[x-i][y-i] == turn)
			    break;
		}
		else {
			if (gameboard[x-i][y-i] == 0) 
			    break;
		    else if (gameboard[x-i][y-i] == turn) {
		    	returnTurn = 1;
		    	points_X[4] = x-i;
		    	points_Y[4] = y-i;
		    	break;
			}
		}
		i++;
	} 
	
	while (x-i>=0 && y-i>=0) { //좌하단  
		if (i==1) {
			if (gameboard[x-i][y+i] == turn)
			    break;
		}
		else {
			if (gameboard[x-i][y+i] == 0) 
			    break;
		    else if (gameboard[x-i][y+i] == turn) {
		    	returnTurn = 1;
		    	points_X[5] = x-i;
		    	points_Y[5] = y+i;
		    	break;
			}
		}
		i++;
	}
	
	while (x+i>=0 && y-i>=0) { // 우상단  
		if (i==1) {
			if (gameboard[x+i][y-i] == turn)
			    break;
		}
		else {
			if (gameboard[x+i][y-i] == 0) 
			    break;
		    else if (gameboard[x+i][y-i] == turn) {
		    	returnTurn = 1;
		    	points_X[6] = x+i;
		    	points_Y[6] = y-i;
		    	break;
			}
		}
		i++;
	} 
	
	while (x+i>=0 && y-i>=0) { //우하단  
		if (i==1) {
			if (gameboard[x+i][y+i] == turn)
			    break;
		}
		else {
			if (gameboard[x+i][y+i] == 0) 
			    break;
		    else if (gameboard[x+i][y+i] == turn) {
		    	returnTurn = 1;
		    	points_X[7] = x+i;
		    	points_Y[7] = y+i;
		    	break;
			}
		}
		i++;
	} 	 
}

void initPoints() {
	int i;
	for(i=0;i<0;i++) {
		points_X[i] = -1;
		points_Y[i] = -1;
	}
}


