#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 6
#define POINTS_SIZE 8

int** gameboard;



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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	init_othello();
    
	return 0;
}
