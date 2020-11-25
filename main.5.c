#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 6
#define FALSE (0)
#define TRUE (1)
#define POINT_UP 0
#define POINT_DOWN 1
#define POINT_LEFT 2
#define POINT_RIGHT 3
#define POINT_LEFTUP_CROSS 4
#define POINT_LEFTDOWN_CROSS 5
#define POINT_RIGHTUP_CROSS 6
#define POINT_RIGHTDOWN_CROSS 7

int**gameboard;

int points_X[8];
int points_Y[8];
//8������ ���� ������ �迭
//������� ��ǥ�� ���ٴ� �� 
int turn = 1;
// 1���� 2 �İ�  
int checkCrossLinePiece(int x, int y, int turn)  {
	//���� ���� �밢���� 8���� ���� üũ�ϰ� �� �� �ִ��� return�Ѵ�.
	//��ǥ������ ���� ���� ���������� ����
	//8������ ��, �Ʒ�, ��, ��, �»��, ���ϴ�, ����, ���ϴ��̴�.
	initPoints();  //8���� �ʱ�ȭ
	
	int returnTurn = 0;
	int i;
	
	for(i=1;y-i>=0;i++) {// �� 
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
	
	for(i=1;y+i>=BOARD_SIZE;i++) {// �Ʒ�  
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
	
	for(i=1;x-i>=0;i++) {// ��  
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
	
	for(i=1;y-i>=0;i++) {// ��  
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
	
	//�밢��
	while (x-i>=0 && y-i>=0) { // �»��  
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
	
	while (x-i>=0 && y-i>=0) { //���ϴ�  
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
	
	while (x+i>=0 && y-i>=0) { // ����  
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
	
	while (x+i>=0 && y-i>=0) { //���ϴ�  
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
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	return 0;
}
