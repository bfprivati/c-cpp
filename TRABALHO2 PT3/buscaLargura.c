/* 	V = Quantidade de vértices
	A = Quantidade de arestas
	a1 e a2 = arestas do grafo
	D (0 ou 1) = Se é grafo ou digrafo
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 50

typedef struct lista{
    int item;
    struct lista *prox;
}LISTA;

typedef struct fila{
    LISTA *first;
    LISTA *last;
}FILA;

FILA* inicializar(){
    FILA*temp;
    temp = (FILA*) malloc(sizeof(FILA));
    temp->first = NULL;
    temp->last = NULL;

    return temp;
}


FILA *retiraFila(FILA *f, int *elem){
    if(f->first != NULL){
        LISTA *aux = f->first;
        *elem = aux->item;
        f->first = f->first->prox;
        if(f->first == NULL)
            f->last = NULL;
        free(aux);
        return f;
    }
    else{
        //printf("fila vazia\n");
        *elem = -1;
        return f;
    }

}

FILA* insereFila(FILA *f, int elem){
    LISTA *aux = (LISTA*)malloc(sizeof(LISTA));
    aux->item = elem;
    aux->prox = NULL;

    if(f->last == NULL){
        f->first = aux;
        f->last = aux;
    }
    else{
        f->last->prox = aux;
        f->last = aux;
    }

    return f;
}

int main()
{
    int V, A, D, i, j, a1, a2;
    int atual;
    FILA *fila;

    fila = inicializar();

    scanf("%d %d %d", &V, &A, &D);

    int grafo[V][V];

	for(i = 0; i<V; i++){	//prenche a matriz do grafo com 0's
		for(j = 0; j<V; j++){
			grafo[i][j] = 0;
		}
	}

	if(D == 0){  //caminho do grafo
		for(i = 0; i < A; i++){	//muda para 1 as posicoes que contem aresta
			scanf("%d %d", &a1, &a2);
			grafo[a1][a2] = 1;
			grafo[a2][a1] = 1;
		}
	}else if(D == 1){
		for(i = 0; i < A; i++){	//muda para 1 as posicoes que contem aresta
			scanf("%d %d", &a1, &a2);
			grafo[a1][a2] = 1;
        }
	}

    fila = insereFila(fila, 0);

    do{
        fila = retiraFila(fila, &atual);
        if(atual != -1){
            if(grafo[atual][atual] != 2){
                grafo[atual][atual] = 2;
                for(i = 0; i < V; i++){
                    if(grafo[atual][i] == 1){
                        if(grafo[i][i] != 2){
                            fila = insereFila(fila, i);
                        }
                    }
                }
                printf("%d ", atual);
            }
        }

    }while(atual != -1);

    return 0;
}

