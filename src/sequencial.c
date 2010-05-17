#include "lib/utilidades.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
	Ponto * p;
	int i;
	unsigned int tam;

	p = le_pontos(&tam);
	
	printf("Quantidade de pontos:%u\n",tam);
	printf("Ponto[%d]=%d\n",tam-1,p[0].x);
	return 0;

}
