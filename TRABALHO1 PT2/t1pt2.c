#include<stdio.h>
#include<stdlib.h>


typedef struct polinomio{
	int coef;
	int pot;
}POLINOMIO

typedef struct lista{
	POLINOMIO dados;
	struct lista *prox, *ant;
}LISTA;

LISTA* criarLista(){   //OK
	return NULL
}

int listaVazia(LISTA *L){   //OK
	if( L == NULL)
		return 1;
	else
		return 0;
}

LISTA* inserir(LISTA *L, int coef, int grau){
	if(listaVazia(L)){
    	LISTA *novo = (LISTA*) malloc(sizeof(LISTA));
    	novo->L.coef = coef;
    	novo->L.pot = grau;
    	novo->prox = lista;
    	novo->ant = NULL;
    	return novo;
	}

	LISTA *novo = (LISTA*) malloc(sizeof(LISTA));
	novo->L.coef = coef;
    novo->L.pot = grau;

	while(L->prox != NULL){

		if(novo->pot == L->pot){  //se a potencia do novo for igual a um elemento da lista
			L->coef =+ novo->coef;
			return L;
		}

		L = L->prox;
	}
	//nao existe coeficiente igual
	if(novo->L.pot < L->pot){ //insere primeira posicao
		novo->prox = L;
		novo->ant = NULL;
		L->ant = novo;
		return novo;
	}

	else{
		LISTA *aux = L;
		while(aux->prox != NULL && novo->L.pot > aux->prox->L.pot){
		    aux = aux->prox;
		}

		novo->prox = aux->prox;
		novo->ant = aux;

		if(aux->prox != NULL)
		    aux->prox->ant = novo;         
		    aux->prox = novo;
		    }
		}

	return L;
}