#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char ** argv)
{

	int x,y;
	int porcentagem;

	if(argc < 4)
	{
		cout << "cria_tabela [altura] [largura] [porcetagem de 1's] " << endl;
		return -1;
	}

	x = atoi(argv[1]);
	y = atoi(argv[2]);
	porcentagem = atoi(argv[3]);

	cout << x << " " << y << endl;


	srand(time(NULL));

	int i,j;

	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if( (rand() % 100) < porcentagem)
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << endl;
	}

	return 0;
}
