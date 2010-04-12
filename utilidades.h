#define ARQUIVO_MUITO_GRANDE		-2
#define ERRO						-1

#define MAX_TAM_X				100
#define MAX_TAM_Y				100


class Matriz
{
	public:
		void imprime();
		int abre_arq(char * nome);
		Matriz(int x, int y);
		Matriz(char * nome_arq);
		~Matriz();

	private:
		// dados
		int tam_x, tam_y;
		char ** matriz;

		// funções auxiliares
		void aloca();
};

void imprime_matriz(int, int);
int abre_matriz(char * arquivo, int *, int *);
