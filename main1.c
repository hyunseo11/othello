#include <stdio.h>
#include <stdlib.h>
#define N 6
int gameboard[N][N];
void init_othello() { //게임초기화
    int i, j;
	for(i=0;i<N;i++) {
		for(j=0;j<N;j++) {
		gameboard[i][j]=0;
	}
	 }   
}


 



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, j;
	
	init_othello(i, j);
    
	return 0;
}
