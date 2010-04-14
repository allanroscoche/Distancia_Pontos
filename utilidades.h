#define ARQUIVO_MUITO_GRANDE		-2
#define ERRO						-1

#define MAX_TAM_X				100
#define MAX_TAM_Y				100

#include <vector>
#include <iostream>

using namespace std;

class Ponto
{
	friend ostream &operator<<(ostream &, const Ponto &);

	public:
		Ponto(int x, int y);
		double distancia(Ponto p);

	//protected:
		int x;
		int y;
		
};

class Matriz
{
	public:
		void imprime();
		int getPontos(vector<Ponto>&);

		Matriz(int x, int y);
		Matriz(char * nome_arq);
		~Matriz();

	private:
		// dados
		int tam_x, tam_y;
		vector<Ponto> L;

};
