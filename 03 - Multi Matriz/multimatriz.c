multm.c 

#include<stdio.h>
#include<stdlib.h>

int main(){
	x=10;
	int a[x][x],b[x][x],c[x][x];
	
	for(int k=0; k<x;k++){
		a[k][k]=1;
		b[k][k]=2;
		c[k][k]=0;
	}

	for(int i=0; i<x;i++){
		for(int j=0; j<x; j++){
			for(int k=0;k<x;k++){
				c[i][j] = c[i][j] + a[i][k]*
 b[k][j];

			}
		}
	}
		
	
	for(int i=0; i<x;i++){
		printf("\n");
		for(int j=0; j<x; j++){
		printf("%d%" , &c[i][j]);
	}
return 0;
}


	
	