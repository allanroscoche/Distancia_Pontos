#define ARQUIVO_MUITO_GRANDE			-2
#define ERRO					-1

#define RED					1
#define BLACK					0

//#define NULL					0

#define ALLOC_SIZE				1000

#define MAX_TAM_X				100
#define MAX_TAM_Y				100


typedef struct Ponto
{
	int x;
	int y;
	int z;
} Ponto;

typedef struct Intervalo{
	unsigned long ini;
	unsigned long fim;
} Intervalo;

typedef struct RB_nodo
{
	int cor;
	double distancia;
	unsigned int contador;
	struct RB_nodo * esquerda;
	struct RB_nodo * direita;
	struct RB_nodo * pai;
} RB_nodo;

typedef struct RB_arvore
{
	RB_nodo * raiz;
} RB_arvore;

RB_nodo * insere_nodo(RB_arvore *, double distancia);
RB_arvore * inicia_arvore(RB_arvore *);

double distancia(Ponto, Ponto);
Ponto * le_pontos(unsigned long *);
void imprime_arvore(RB_arvore * p);
void imprime_nodo(RB_nodo * no);
void indices(unsigned long , unsigned int *, unsigned int *, unsigned long tam);
