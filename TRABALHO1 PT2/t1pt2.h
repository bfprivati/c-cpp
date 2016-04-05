//ARQUIVO COM DECLARAÇÃO DAS FUNÇÕES UTILIZADAS

typedef struct polinomio POLINOMIO;
typedef struct lista LISTA;

LISTA* criarLista(LISTA *L);  //OK
// Inicializa a lista
int listaVazia(LISTA *L); 	//OK
//verifica se a lista esta vazia
LISTA* inserir(LISTA *L, int coef, int grau);  //OK
//inserir ordenado na lista