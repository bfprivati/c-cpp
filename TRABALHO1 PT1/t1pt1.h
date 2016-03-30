//ARQUIVO COM DECLARAÇÃO DAS FUNÇÕES UTILIZADAS

typedef struct produto PRODUTO;
typedef struct lista LISTA;

void criarLista(LISTA *L);  //OK
// Inicializa a lista
int inserirProduto(LISTA *L, PRODUTO p);
// Inserre um produto em ordem ordenada pelo codigo, não podendo repetir o mesmo codigo para produtos diferentes
int removerProduto(LISTA *L, int n);
// Remove os N primeiros elementos da lista
int trocaProduto(LISTA *L, int pos1, int pos2);
// Troca dois elementos de posiçao, 
int buscaProduto(LISTA *L);
// Retorna a posicao e o produto com menor quantidade de peças em estoque
int efetuarCompra(LISTA *L, int codProd, int qtde);
//Faz a compra de um produto. O cliente insere a qtd desejada, e a função decrementa o estoque
void imprimeLista(LISTA *L);   //OK
//Imprime a lista de produtos