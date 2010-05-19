#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "utilidades.h"

#define BUFF_MAX	30

double distancia(Ponto p1, Ponto p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) + (p1.z-p2.z)*(p1.z-p2.z));
}
RB_nodo * cria_nodo(double data)
{
	RB_nodo * no;
	no = (RB_nodo *) malloc(sizeof(RB_nodo));

	memcpy(&(no->distancia),&data,sizeof(double));
	
	return no;
}

RB_nodo * insere_nodo(RB_arvore * arvore, double distancia)
{
	RB_nodo * n;
	RB_nodo * pai;

	pai = NULL;
	n=arvore->raiz;
	while(n != NULL)
	{
		pai = n;
		if     (distancia < n->distancia)
			n = n->esquerda;
		else if(distancia > n->distancia)
			n = n->direita;
		else if(distancia == n->distancia)
		{
			n->contador++;
			return n;
		}
	}
	
	n = cria_nodo(distancia);
	if(pai == NULL)
		arvore->raiz = n;
	else {
		if(distancia < pai->distancia)
			pai->esquerda = n;
		else if(distancia > pai->distancia)
			pai->direita = n;
		else
			return NULL;
		n->pai = pai;
	}
	n->contador = 1;

	return n;
	
 	return NULL;
}
RB_arvore * inicia_arvore(RB_arvore * arvore)
{
	if(arvore == NULL)
		arvore = (RB_arvore *) malloc(sizeof(RB_arvore));

	arvore->raiz = NULL;


	return arvore;
}

void imprime_arvore(RB_arvore * p)
{
	if(p->raiz != NULL)
		imprime_nodo(p->raiz);
	else
		printf("arvore vazia\n");
}

void imprime_nodo(RB_nodo * no)
{
	if(no->esquerda != NULL)
		imprime_nodo(no->esquerda);
	printf("distancia:%10f contador:%d \n",no->distancia,no->contador);
	if(no->direita != NULL)
		imprime_nodo(no->direita);
}

Ponto * le_pontos(unsigned int * tam){
	int result;
	unsigned int count;
	unsigned int quant_alloc,count_alloc;
	Ponto *p=0;

	count=0;
	quant_alloc=1;
	count_alloc=0;

	do
	{		
		if(count_alloc <= 0)
		{
			p = (Ponto *) realloc(p,quant_alloc++*ALLOC_SIZE*sizeof(Ponto));
			count_alloc = ALLOC_SIZE;
		}

		count_alloc--;
		result = scanf("%d %d %d", &(p[count].x), &(p[count].y),&(p[count].z));
		if(result < 3)
			break;

		count++;
		quant_alloc++;
		
	}while(result != EOF);
	p = (Ponto *) realloc(p,count*sizeof(Ponto));

	*tam = count;	
	return p;
}
