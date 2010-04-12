#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "utilidades.h"

using namespace std;

Matriz::Matriz(int x, int y)
{
	tam_x = x;
	tam_y = y;

	this->aloca();

}
void Matriz::aloca()
{
	int i;

	matriz = (char**)malloc(tam_x * sizeof(int));
	for(i=0;i<tam_x;i++)
		matriz[i] = (char*)malloc(tam_y * sizeof(char));
	
}
Matriz::Matriz(char * nome_arquivo)
{
	int i,j;
	int x,y;

	ifstream arq;
	arq.open(nome_arquivo);

	
//	cout << "x:" << x << " y:" << endl;

	arq.close();
	
}
Matriz::~Matriz(void)
{
	int i;
	for(i=0;i<tam_x;i++)
		free(matriz[i]);
}

void Matriz::imprime()
{
	int i,j;
	for(i=0;i<tam_x;i++)
	{
		for(j=0;j<tam_y;j++)
			cout << matriz[i][j] << " ";
		cout << endl;
	}
}

char matriz[MAX_TAM_X][MAX_TAM_Y];
const char mode = 'r';
int abre_matriz(char * arquivo, int *x_tam, int *y_tam)
{
	int i,j;
	int tam_x, tam_y;
	FILE * arq;

	// Abre o arquivo
	arq = fopen(arquivo,&mode);
	fscanf(arq,"%d %d\n",&tam_x, &tam_y);
	printf("Lin:%d Col:%d\n",tam_x,tam_y);
	
	// Verifica se está dentro dos limites da memória
	if((tam_x > MAX_TAM_X) || (tam_y > MAX_TAM_Y))
		return ERRO;
	
	for(i=0;i<tam_x;i++){
		for(j=0;j<tam_y;j++)
			fscanf(arq,"%d",&matriz[i][j]);
		fscanf(arq,"\n");
	}
			
	// Fecha o arquivo
	fclose(arq);
	
	imprime_matriz(tam_x,tam_y);

	// atribui os valores de returno
	*x_tam = tam_x;
	*y_tam = tam_y;

}

void imprime_matriz(int x, int y)
{
	int i,j;
	printf("\n");
	for(i=0;i<x;i++){
		for(j=0;j<y;j++)
			printf("%d ",matriz[i][j]);
		printf("\n");
	}
	printf("\n");
}
