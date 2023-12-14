#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int v[1000];
int s1=0, s2=0;
sem_t arrive1, arrive2;


void* soma(void * arg)
{
        int i;
        for(i = 0; i <= 499; i = i + 1)
                s1 = s1 + v[i];

        printf("Soma chegou na Barreira!!");

        sem_post(&arrive2);
        sem_wait(&arrive1);
}
int main()
{
        pthread_t tid; //pode usar variavel para escolher valor

        sem_init(&arrive1,0,0);
        sem_init(&arrive2,0,0);

        int i;
        for(i=0; i<1000; i++)
                v[i]=1;


        printf("Inicio do  main...\n");
        pthread_create(&tid,NULL,soma,NULL);


        for(i = 500; i <= 999; i++)
                s2 = s2 + v[i];

        printf("Main chegou na Barreira!!");

        sem_post(&arrive1);
        sem_wait(&arrive2);

        int somaFinal = s1 
 int somaFinal = s1 + s2;
        printf("soma do vetor: %d \n", somaFinal);

        sem_destroy(&arrive1);
        sem_destroy(&arrive2);

return 0;
}