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
