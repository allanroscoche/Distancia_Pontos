#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "utilidades.h"

#define BUFF_MAX	30

using namespace std;

Matriz::Matriz(int x, int y)
{
	tam_x = x;
	tam_y = y;

	this->aloca();

}
Matriz::Matriz(char * nome_arquivo)
{
	int i,j;
	int x,y;
	char ch, buffer[BUFF_MAX];

	ifstream arq;
	arq.open(nome_arquivo);

	// lê x
	i=0;
	do{
		arq.get(ch);
		buffer[i++]=ch;
	}while((ch != ' ') && (i<BUFF_MAX));
	x = atoi(buffer);

	// lê y
	i=0;
	do{
		arq.get(ch);
		buffer[i++]=ch;
	}while((ch != '\n') && (i<BUFF_MAX));
	y = atoi(buffer);

	cout << "x:" << x << " y:" << y << endl;
	tam_x = x;
	tam_y = y;
	this->aloca();

	for(i=0;i<tam_x;i++)
	{
		for(j=0;j<tam_y;j++)
		{
			// carrega o valor
			arq.get(ch);
			if(ch=='0')
				matriz[i][j]='0';
			else
				matriz[i][j]='1';
			// espaco ou fim de linha
			arq.get(ch);
		}
	}

	arq.close();
	
}
Matriz::~Matriz(void)
{
	int i;
	for(i=0;i<tam_x;i++)
		free(matriz[i]);
}

void Matriz::aloca()
{
	int i;

	matriz = (char**)malloc(tam_x * sizeof(int));
	for(i=0;i<tam_x;i++)
		matriz[i] = (char*)malloc(tam_y * sizeof(char));
	
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

int Matriz::getPontos(std::list<int>& lista)
{
	int i, j;
	for(i=0;i<tam_x;i++)
		for(j=0;j<tam_y;j++)
			if(matriz[i][j]=='1')
			{
				//lista.pushfront(1);
			}
}

