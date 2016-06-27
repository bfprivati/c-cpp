/* 	V = Quantidade de vértices
	A = Quantidade de arestas
	a1 e a2 = arestas do grafo
	a3 = peso da aresta
	D (0 ou 1) = Se é grafo ou digrafo
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int V, A, D, a1, a2, a3;
    int i, j, k, menor, atual, proximo;

    scanf("%d %d %d", &V, &A, &D);

    int grafo[V][V];
    int visitados[V];

	for(i = 0; i<V; i++)	//prenche a matriz do grafo com 0's
		for(j = 0; j<V; j++)
			grafo[i][j] = 0;

	if(D == 0){  //caminho do grafo
		for(i = 0; i < A; i++){	//muda para 1 as posicoes que contem aresta
			scanf("%d %d %d", &a1, &a2, &a3);
			grafo[a1][a2] = a3;
			grafo[a2][a1] = a3;
		}
	}else if(D == 1){
		for(i = 0; i < A; i++){	//muda para 1 as posicoes que contem aresta
			scanf("%d %d %d", &a1, &a2, &a3);
			grafo[a1][a2] = a3;
        }
	}

    atual = 0;

    for(i = 0; i < V; i++){
        visitados[atual] = 1;
        printf("%d ", atual);
        menor = 0;
        for(k = 0; k < V; k++){
            if(visitados[k] == 1){
                atual = k;
                for(j = 0; j < V; j++){
                    if(grafo[atual][j] != -1){
                        if(visitados[j] != 1){
                            if(menor == 0){
                                menor = grafo[atual][j];
                                proximo = j;
                            }
                            else{
                                if(menor > grafo[atual][j]){
                                    menor = grafo[atual][j];
                                    proximo = j;
                                }
                            }
                        }
                    }
                }
            }
        }

        atual = proximo;
    }

    return 0;
}


