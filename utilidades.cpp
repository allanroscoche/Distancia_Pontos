#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <fstream>

#include "utilidades.h"

#define BUFF_MAX	30

using namespace std;

Ponto::Ponto(int i, int j)
{
	x=i;
	y=j;
}
ostream &operator<<(ostream &output, const Ponto &p)
{
   output << "x:" << p.x << " y:" << p.y <<  endl;
   return output;
}

double Ponto::distancia(Ponto p)
{
	return abs( (p.x - x) + (p.y - y));
}

Matriz::Matriz(int x, int y)
{
	tam_x = x;
	tam_y = y;

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
	

	for(i=0;i<tam_x;i++)
	{
		for(j=0;j<tam_y;j++)
		{
			// carrega o valor
			arq.get(ch);
			// Adiciona o ponto a lista
			if(ch == '1'){
				Ponto p(i,j);
				L.push_back(p);
			}
		
			// espaco ou fim de linha
			arq.get(ch);
		}
	}

	arq.close();
	
}
Matriz::~Matriz(void)
{

}



void Matriz::imprime()
{
	int i,j;
	char matriz[tam_x][tam_y];

	for(i=0;i<tam_x;i++)
		for(j=0;j<tam_y;j++)
			matriz[i][j]='0';

	vector<Ponto>::iterator ii;

	for(ii=L.begin(); ii != L.end(); ++ii)
	{
		matriz[ii->x][ii->y]='1';
	}

	for(i=0;i<tam_x;i++)
	{
		for(j=0;j<tam_y;j++)
			cout << matriz[i][j] << " ";
		cout << endl;
	}

}

int Matriz::getPontos(std::vector<Ponto>& lista)
{
	lista = L;
	return L.size();
}

