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
	
	//printf("Quantidade de pontos:%u\n",tam);
	//printf("Quantidade de distancias:%u\n",total_tam);

	pthread_mutex_init(&novo_nodo,&att);
	a = NULL;
	a = inicia_arvore(a);

	Intervalo intervalo[NUM_THREADS];
	int ini, fim, aux;
	aux = (total_tam-1) / NUM_THREADS;
	ini = 0;
	fim = aux;
	for(i=0;i<NUM_THREADS;i++) // Divide o trabalho igualmente entre as threads
	{
		intervalo[i].ini = ini;
		intervalo[i].fim = fim;

		pthread_create(&proc[i],  	NULL, (void *) &trabalhador, 	    	(void *)&intervalo[i]);

		ini = fim+1;
		fim = fim + aux + 1;
		if(fim > (total_tam-1))
			fim=total_tam-1;
		
	}
	for(i=0;i<NUM_THREADS;i++) // Espera as threads terminarem
	  pthread_join(proc[i],(void *) &status);
	imprime_distancias(a);

	return 0;
}

void trabalhador(void * t)
{
	unsigned int i,j,cont;
	unsigned long cont_buf;
	Intervalo * inter;

	cont_buf = 0;
	inter = (Intervalo *) t;
	//printf("%02d->%02d\n",inter->ini,inter->fim);

	unsigned long ini_u,ini_v,fim_u,fim_v;
	indices(inter->ini,&ini_u,&ini_v,tam); // determina quais são os índices do início
	indices(inter->fim,&fim_u,&fim_v,tam); // determina quais são os índices do final
	cont = inter->ini;

/* Combinações entre os pontos.
	ini			fim
u	n	n	n	(n+1)
v	n+1	n+2	n+3	(n+1)+1
*/
	// Calcula as distâncias até o próximo v=n+1, se necessário.
	if(fim_u > ini_u){
		for(j=ini_v;j<tam;j++)
		{
			insere_nodo(a,distancia(p[ini_u],p[j]));
			//printf("[%2d] = p[%d] p[%d]\n",cont++, ini_u, j);
		}
	}
	// Calcula as distâncias com u's completos.
	for(i=ini_u+1;i<fim_u;i++)
	{
		for(j=i+1;j<tam;j++)
		{
			insere_nodo(a,distancia(p[i],p[j]));
			//printf("[%2d] = p[%d] p[%d]\n",cont++, i, j);
		}
	}
	// Calculas as outras distâncias, até o último v.
	for(j=fim_u+1;j<=fim_v;j++)
	{
		insere_nodo(a,distancia(p[fim_u],p[j]));
		//printf("[%2d] = p[%d] p[%d]\n",cont++, fim_u, j);
	}
	
}

