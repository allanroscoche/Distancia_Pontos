#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "utilidades.h"

#define BUFF_MAX	30

double distancia(Ponto p1, Ponto p2)
{
	return abs( (p2.x - p1.x) + (p2.y - p1.y));
}
RB_nodo * cria_nodo(Dist data)
{
	RB_nodo * no;
	no = (RB_nodo *) malloc(sizeof(RB_nodo));

	memcpy(&(no->valor),&data,sizeof(Dist));
	
	return no;
}

RB_nodo * insere_nodo(RB_arvore * arvore, Dist valor)
{
	if(arvore->raiz == NULL)
	{
		arvore->raiz = cria_nodo(valor);
		arvore->raiz->cor = BLACK; 
		return arvore->raiz;
	}

 	return NULL;
}
void inicia_arvore(RB_arvore * arvore)
{
	if(arvore == NULL)
		arvore = (RB_arvore *) malloc(sizeof(RB_arvore));

	arvore->raiz = NULL;
}
Ponto * le_pontos(unsigned int * tam){
	unsigned int count;
	unsigned int i,quant_alloc,count_alloc;
	Ponto *p=0;

	count=0;
	quant_alloc=1;
	count_alloc=0;

	while(getchar() != EOF)
	{
		
		if(count_alloc <= 0)
		{
			p = (Ponto *) realloc(p,quant_alloc++*ALLOC_SIZE*sizeof(Ponto));
			count_alloc = ALLOC_SIZE;
		}

		count_alloc--;
		scanf("%d %d %d", &(p[count].x), &(p[count].y),&(p[count].z));
		count++;

		quant_alloc++;
		
	}
	p = (Ponto *) realloc(p,count*sizeof(Ponto));

	*tam = count;	
	return p;
}
