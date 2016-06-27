/* 	V = Quantidade de vértices
	A = Quantidade de arestas
	a1 e a2 = arestas do grafo
	D (0 ou 1) = Se é grafo ou digrafo
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 50

typedef struct lista{	//estrutura para lista de visitados
	int vetor[MAX];
	int fim;
}LISTA;

typedef struct pilha{	//estrutura auxiliar na busca de profundidade
  int pilha[MAX];
  int topo;
}PILHA;


PILHA* InicializaPilha(){
    PILHA* pilha =(PILHA*)malloc(sizeof(PILHA));
    return pilha;
}

void criaPilha(PILHA *p){  //OK
  p->topo=0;
}

int pilhaCheia(PILHA *p){ //OK
  if(p->topo == MAX)
    return 1;
  else
    return 0;
}

int pilhaVazia(PILHA *p){ //OK
  if(p->topo == 0)
    return 1;
  else
    return 0;
}

void push(PILHA *p, int v){   //OK
  if (pilhaCheia(p))   //OVERFLOW
    return;

  p->pilha[p->topo] = v;
  p->topo++;

}

int pop(PILHA *p){
  int x;
  if(pilhaVazia(p))  //UNDERFLOW
    return 0;

  //*elem = (p->pilha[p->topo-1]);
  x = p->pilha[p->topo-1];
  p->topo--;
  return x;
}

void buscaProfundidade(int V, int grafo[V][V], int ini){
	LISTA lista;
	PILHA pilha;
	int i =0, j=0; //linha, coluna
	int aux, comp, k;

    lista.fim = 0;
	lista.vetor[0] = ini;
	lista.fim ++;

    InicializaPilha();
	criaPilha(&pilha);
	push(&pilha, ini);

	while( pilhaVazia(&pilha) != 1 ){ //enquanto a pilha nao for vazia
		for(j = 0; j < V; j++){
			if(grafo[i][j] == 1){ //se achou aresta

				comp = 0;
                k =0;

				for(k = 0; k < lista.fim; k++) //ok verifica se ja foi visitado
					if (j == lista.vetor[k])
						comp = 1;

				if(comp == 0){
					push(&pilha, j);
                }
			}
		}

		aux = pop(&pilha); //aux recebe o ultimo conteudo da pilha
        i = aux;

        for(k =0; k < lista.fim; k++){ //verifica se já foi visitado
            if(i == lista.vetor[k])
                aux = pop(&pilha);
                i = aux;
		}

		lista.vetor[lista.fim] = aux; //enfileira o ultimo conteudo
        lista.fim++;

	}
	for(i =0; i<V; i++)
		printf("%d ", lista.vetor[i]);

}

int main(){
	int V, A, a1, a2, D;
	int i, j;

	scanf("%d %d %d", &V, &A, &D);

	int gr[V][V];

	for(i = 0; i<V; i++){	//prenche a matriz do grafo com 0's
		for(j = 0; j<V; j++){
			gr[i][j] = 0;
		}
	}

	if(D == 0){
		for(i = 0; i < A; i++){	//muda para 1 as posicoes que contem aresta
			scanf("%d %d", &a1, &a2);
			gr[a1][a2] = 1;
			gr[a2][a1] = 1;
		}
	}else if(D == 1){
		for(i = 0; i < A; i++){	//muda para 1 as posicoes que contem aresta
			scanf("%d %d", &a1, &a2);
			gr[a1][a2] = 1;
        }
	}

  /* printf("\n Matriz\n");
    for(i = 0; i<V; i++){	//prenche a matriz do grafo com 0's
		for(j = 0; j<V; j++){
			printf("%d ", gr[i][j]);
		}
        printf("\n");
	} */

	int ini =0;

	buscaProfundidade(V, gr, ini);


	return 0;
}

