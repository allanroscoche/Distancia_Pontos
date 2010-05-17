#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char ** argv)
{
	int x_max;
	int y_max;
	int z_max;
	int quantidade_pontos;

	if(argc < 5){
		printf("cria_pontos x_max y_max z_max quantidade_de_pontos\n");
		return 1;
	}
	x_max = atoi(argv[1]);
	y_max = atoi(argv[2]);
	z_max = atoi(argv[3]);
	quantidade_pontos = atoi(argv[4]);

	srand(time(NULL));

	int i;
	int x,y,z;
	for(i=0;i<quantidade_pontos;i++)
	{
		x = rand() % x_max;
		y = rand() % y_max;
		z = rand() % z_max;
		printf("%d %d %d\n", x, y, z);
	}
	return 0;
}

	
