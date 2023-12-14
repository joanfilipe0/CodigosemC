#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

long quantidade = 0;  // Variavel Global, compartilhada
sem_t s;

void * incrementa(void * args)
{

        long i,temp;
        for(i=0; i<10000; i++)
        {
                sem_wait(&s);
                temp=quantidade;
                temp++;
                quantidade=temp;
                sem_post(&s);   //liberar semaforo
        }
}

int main()
{
        sem_init(&s,0,1);

        pthread_t t1, t2;

        
        pthread_create(&t1, NULL, incrementa, NULL);  //Filia 1
        pthread_create(&t2, NULL, incrementa, NULL); //Filial 2

        //join
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        printf("Quantidade = %ld \n", quantidade);
        sem_destroy(&s);
return 0;
}