#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/utilidades.h"

#define TAM_BUFFER		1000000

void produtor(void *);
void consumidor(void *);

double buffer[TAM_BUFFER];
Ponto * p;
RB_arvore * a;
sem_t itens;
sem_t espacos;

int main(void)
{

	pthread_t prod;
	pthread_t cons;
	int status;
	unsigned int i,j;
	
	double dist;

	unsigned long tam;

	sem_init(&itens, 0, 0);
	sem_init(&espacos, 0, TAM_BUFFER);

	p = le_pontos(&tam);
	
	printf("Quantidade de pontos:%u\n",tam);
	printf("Quantidade de distancias:%u\n",(tam*(tam-1)/2));

	a = NULL;
	a = inicia_arvore(a);

	pthread_create(&prod,  	NULL, (void *) &produtor, 	    	(void *)tam);
	pthread_create(&cons,  	NULL, (void *) &consumidor,	    	(void *)tam);
	pthread_join(prod, &status);
	pthread_join(cons, &status);

	imprime_arvore(a);

	return 0;
}

void produtor(void * tamanho)
{
	unsigned int i,j;
	unsigned long cont_buf,tam;

	cont_buf = 0;
	tam = (unsigned long)tamanho;

	for(i=0;i<tam;i++)
	{
		for(j=i+1;j<tam;j++)
		{
			sem_wait(&espacos);
			buffer[ cont_buf++ % TAM_BUFFER ] = distancia(p[i],p[j]);
			sem_post(&itens);
		}
	}

}
void consumidor(void * tamanho)
{
	unsigned int i,j;
	unsigned long cont_buf,tam;

	cont_buf = 0;
	tam = (unsigned long)tamanho;

	for(i=0;i<tam;i++)
	{
		for(j=i+1;j<tam;j++)
		{
			sem_wait(&itens);
			insere_nodo(a, buffer[ cont_buf++ % TAM_BUFFER ]);
			sem_post(&espacos);
		}
	}

}
