#define PARALELO
#define NUM_THREADS		2

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/utilidades.h"

void trabalhador(void *);

Ponto * p;
RB_arvore * a;
unsigned long tam;

extern pthread_mutex_t novo_nodo;

int main(void)
{
	pthread_mutexattr_t att;
	pthread_t proc[NUM_THREADS];
	int status;
	unsigned int i,j;
	
	double dist;
	unsigned long total_tam;

	p = le_pontos(&tam);
	total_tam = tam*(tam-1)/2;
	
	printf("Quantidade de pontos:%u\n",tam);
	printf("Quantidade de distancias:%u\n",total_tam);

	pthread_mutex_init(&novo_nodo,&att);
	a = NULL;
	a = inicia_arvore(a);

	Intervalo intervalo[NUM_THREADS];
	int ini, fim, aux;
	aux = (total_tam-1) / NUM_THREADS;
	ini = 0;
	fim = aux;
	for(i=0;i<NUM_THREADS;i++)
	{
		intervalo[i].ini = ini;
		intervalo[i].fim = fim;
		pthread_create(&proc[i],  	NULL, (void *) &trabalhador, 	    	(void *)&intervalo[i]);
		pthread_join(proc[i], &status);

		ini = fim+1;
		fim = fim + aux + 1;
		if(fim > (total_tam-1))
			fim=total_tam-1;
		
	}
	imprime_arvore(a);

	return 0;
}

void trabalhador(void * t)
{
	unsigned int i,j,cont;
	unsigned long cont_buf;
	Intervalo * inter;

	cont_buf = 0;
	inter = (Intervalo *) t;
	printf("%02d->%02d\n",inter->ini,inter->fim);

	unsigned long ini_u,ini_v,fim_u,fim_v;
	indices(inter->ini,&ini_u,&ini_v,tam);
	indices(inter->fim,&fim_u,&fim_v,tam);
	cont = inter->ini;

	if(fim_u > ini_u){
		for(j=ini_v;j<tam;j++)
		{
			printf("[%2d] = p[%d] p[%d]\n",cont++, ini_u, j);
		}
	}
	for(i=ini_u+1;i<fim_u;i++)
	{
		for(j=i+1;j<tam;j++)
		{
			//insere_nodo(a,distancia(p[i],p[j]));
			printf("[%2d] = p[%d] p[%d]\n",cont++, i, j);
		}
	}
	for(j=fim_u+1;j<=fim_v;j++)
	{
		printf("[%2d] = p[%d] p[%d]\n",cont++, fim_u, j);
	}
	
}

