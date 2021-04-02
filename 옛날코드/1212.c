#include <stdio.h>
#include <stdlib.h>
int num;
void nojam1212(){
	scanf("%o",&num);
	int N;
	while(num!=0){
		N=num/2;
		int bi;
		bi = num - N*2;
		num=N;
		printf("%d",bi);
	}
	printf("\n");
}

int main(){
	nojam1212();
}
