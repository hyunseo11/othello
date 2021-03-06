int checkCrossLinePiece(int x, int y, int turn)  {
	//가로 세로 대각선의 8방향 돌을 체크하고 둘 수 있는지 return한다.
	//좌표지접에 대한 값은 전역변수에 저장
	//8방향은 위, 아래, 좌, 우, 좌상단, 좌하단, 우상단, 우하단이다.
	initPoints();  //8방향 초기화
	
	char false;
	char true;
	
	int returnTurn = false;
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
			returnTurn = true;
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
			returnTurn = true;
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
			returnTurn = true;
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
			returnTurn = true;
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
		    	returnTurn = true;
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
		    	returnTurn = true;
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
		    	returnTurn = true;
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
		    	returnTurn = true;
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
