#include <stdio.h>
#include <stdlib.h>
#define N 6
int gameboard[N][N];

int othello() {  //��ġ�������
 
	int s, t;

    while() {
		printf("----a--b--c--d--e--f--g--h\n");
		for(s=0;s<8;s++){
			printf("%d", s);}
		for(t=0;t<8;t++){
			printf("%c", gameboard[s][t]);
			printf("\n");
		}
}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int result;
	
	result = othello();
	printf("��� �� ���� ��ġ�� �����ϼ���\n");
	
	
	return 0;
}
