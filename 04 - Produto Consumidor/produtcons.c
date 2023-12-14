#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define TAMANHO 100

int buffer[TAMANHO];
int tail = 0;
int head = 0;
int quantidade = 0;

sem_t empty, full;

void * produtor(void * args)
{
    int i;

    for(i = 1; i <= TAMANHO; i++) {
        sem_wait(&empty);

        printf("Produzindo... %d \n", i);

        buffer[tail] = i;
        tail = (tail + 1) % TAMANHO;
        quantidade++;

        sem_post(&full);
    }
}

void * consumidor(void * args)
{
    int i;
    int soma = 0;

    for(i = 1; i <= TAMANHO; i++) {
        sem_wait(&full);

        int tmp = buffer[head];

        printf("Consumindo... %d\n", tmp);

        head = (head + 1) % TAMANHO;
        quantidade--;
        soma = soma + tmp;

        sem_post(&empty);
    }

    printf("Soma = %d\n", soma);
}

int main() {
    pthread_t p,c;
    sem_init(&full, 1, 0);
    sem_init(&empty, 1, TAMANHO);

    printf("Inicio da main\n");

    pthread_create(&c, NULL, consumidor, NULL);
    pthread_create(&p, NULL, produtor, NULL);
    pthread_join(c, NULL);
    pthread_join(p, NULL);

    sem_destroy(&full);
    sem_destroy(&empty);

    printf("Fim da main\n");
}