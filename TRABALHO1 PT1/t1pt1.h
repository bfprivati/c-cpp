//ARQUIVO COM DECLARAÇÃO DAS FUNÇÕES UTILIZADAS

typedef struct produto PRODUTO;
typedef struct lista LISTA;

void criarLista(LISTA *L);  //OK
// Inicializa a lista
int inserirProduto(LISTA *L, PRODUTO *p);  //OK, REVER ORDENAÇÃO
// Inserre um produto em ordem ordenada pelo codigo, não podendo repetir o mesmo codigo para produtos diferentes
int removerProduto(LISTA *L, int n);  //OK
// Remove os N primeiros elementos da lista
int trocaProduto(LISTA *L, int pos1, int pos2);  //OK
// Troca dois elementos de posiçao,
int buscaProduto(LISTA *L);  //OK
// Retorna a posicao e o produto com menor quantidade de peças em estoque
int efetuarCompra(LISTA *L, int codProd, int qtde);  //OK
//Faz a compra de um produto. O cliente insere a qtd desejada, e a função decrementa o estoque
void mostrarElemento(LISTA *L, int pos);
//Mostra o elemento com menor estoque na lista
void imprimeLista(LISTA *L);   //OK
//Imprime a lista de produtos
