#include "utilidades.h"
//#include "stdlib.h"
#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
	P *p;
	int numPontos;

	// cria a matriz através da entrada padrão
	Matriz m;

	// recebe o número de pontos
	numPontos = m.numPontos();
	cout << "Num Pontos:" << numPontos << endl;
	// aloca o vetor de pontos
	p = (P *)calloc(numPontos,sizeof(P));
	if(p==NULL) return 0;
	// copia os pontos
	m.getPontos(p);

	// Efetua o processamento
	int i,j;
	for(i=0;i<(numPontos-1);i++)
	{
		for(j=i+1;j<numPontos;j++)
			distancia(p[i],p[j]);
	}

	cout << "Finalizado" << endl;
	return 0;

}
