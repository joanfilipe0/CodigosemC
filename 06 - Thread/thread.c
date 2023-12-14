#include<studio.h>
#include<stdlib.h>
#include<pthread>


#define n 5000
	long double a[n][n],b[n][n],c[n][n];

void* mult (void * args) {
	int id = *(int *) args;
	int prim = (id);
	int ult = prim +1;
	for(int m=0; prim<ult; prim++){
		for(int j=0; j<n; j++){
		c[prim][j] = 0;
			for(int k=0;k<n; k++)
			c[prim][j] = c[prim][j] + a[prim][k] * b[k][j];
		}
	}
}
int main(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
		a[i][j] = 1;
		b[i][j] = 2;
		}
	}
pthread_t tid[n];
int args[n];
int k;

for(k=0; k<n; k++)
agrs[k] = k;
for(k=0; k<n; k++)
ptrhead_create(&tid[k],NULL,mult,&args[k]);
for(k=0; k<n; k++)
pthread_join(tid[k], NULL);

return 0;
}
