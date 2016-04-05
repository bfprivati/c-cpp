//ARQUIVO COM DECLARAÇÃO DAS FUNÇÕES UTILIZADAS

typedef struct polinomio POLINOMIO;
typedef struct lista LISTA;

LISTA* criarLista(LISTA *L);  //OK
// Inicializa a lista
int listaVazia(LISTA *L); 	//OK
//verifica se a lista esta vazia
LISTA* inserir(LISTA *L, int coef, int grau);  //OK
//inserir ordenado na lista
void imprimir(LISTA *L);
//imprime o polinomio inversamente ao adicionado
LISTA* excluiTermo(LISTA *L, int grau);
//elimina o termo que contem a potencia igual à inserida pelo usuario
LISTA* esvaziaLista(LISTA *L);
//reinicializa o polinomio, zerando a lista
int calcula(LISTA *L, int x);
//calcula o polinomio inserido, usando o valor de x que o usuario inseriu