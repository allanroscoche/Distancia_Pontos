#include "lib/utilidades.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
	unsigned int i,j;
	Ponto * p;
	RB_arvore * a = NULL;
	double dist;

	unsigned long tam;

	p = le_pontos(&tam);
	
	printf("Quantidade de pontos:%u\n",tam);
	printf("Quantidade de distancias:%u\n",(tam*(tam-1)/2));

	a = inicia_arvore(a);

	
	for(i=0;i<tam;i++)
	{
		for(j=i+1;j<tam;j++)
		{
			dist = distancia(p[i],p[j]);
			//printf("p[%d] p[%d] = %10f\n",i,j,dist);
			insere_nodo(a,dist);
		}
	}	

	imprime_arvore(a);

	return 0;

}
