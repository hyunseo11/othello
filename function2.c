int checkPoint(int x, int y, int turn) {
	int checkPoint = checkInputPoint(x, y, turn);
	int checkClose = checkClosePiece(x, y, turn);
	int checkCross = checkCrossLinePiece(x, y, turn);
	
	return checkPoint && checkClose && checkCross;
}

int checkPointStart(int x, int y, int turn) {
	char false;
	if (x<0 || y<0 || x>BOARD_SIZE || y>BOARD_SIZE)
	return false;
	int checkClose = checkClosePiece(x, y, turn);
	int checkCross = checkCrossLinePiece(x, y, turn);
	
	return checkClose && checkCross;
}

void initGameEndCheckFlag() {
	char false;
	checkedTurn_player1 = false;
	checkedTurn_player2 = false;
}

int isGameEnd() {
	char false;
	char true;
    int endCheck = false;
    
	// 양쪽 플레이어 모두 뒤집기가 가능한 칸이 없는 경우
	if (checkedTurn_player1 && checkedTurn_player2) {
		endCheck = true;
		return endCheck;
	} 
	// 판의 자리가 없을 때
	int remainBoard = BOARD_SIZE * BOARD_SIZE - totalPieceOnBoard;
	if (remainBoard == 0) {
		endCheck = true;
		return endCheck;
	} 
	
	return endCheck;
}

int checkInputPoint(int x, int y, int turn) {
	char true;
	char false;
	
	int pointExist = true;
	
	if(gameboard[x][y] != false)
	   pointExist = 0;
	   
	return pointExist;
}

int checkClosePiece(int x, int y, int turn) {
	char false;
	char true;
	//근처에 상대방의 돌이 있을 때
	int i, j;
	for (i=-1;i<2;i++) {
		for (j=-1;j<2;j++) {
			if (x+i>BOARD_SIZE || y+j>BOARD_SIZE || x+i <=0 || y+j <=0)
			   continue;
		    if (turn == 1){
		    	if (gameboard[x+i][y+j] == 2 && gameboard[x+i][y+j] != 0) {
		    		return true;
				}
			}
		    else {
		    	if (gameboard[x+i][y+j] == 1 && gameboard[x+i][y+i] != 0) {
		    		return true;
				}
			}
		}
	}
	return false; 
}
