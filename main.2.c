#include <stdio.h>
#include <stdlib.h>
#define N 6
int gameboard[N][N];

int othello() {  //배치상태출력
 
	int s, t;

		printf("  0 1 2 3 4 5 \n"); 
		for(s=0;s<6;s++) {
			printf("----------------\n"); 
			printf("%d|", s);
		for(t=0;t<6;t++) {
			printf("%c|", gameboard[s][t]);
		  }
	
	    printf("\n");
	    
	    
}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int result;
	
	result = othello();
	
	
	return 0;
}
