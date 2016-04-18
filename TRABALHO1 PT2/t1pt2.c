#include<stdio.h>
#include<stdlib.h>
#include"t1pt2.h"

typedef struct polinomio{
	int coef;
	int pot;
	struct polinomio *prox; *ant;
}POL;

POL* criarPOL(POL* P){   //OK
	P->coef = 0;
	P->pot = 0;

	return P;
}

int listaVazia(POL *P){   //OK
	if(P == NULL)
		return 1;
	else
		return 0;
}

POL* inserir(POL *P, int coef, int grau){
	
	POL *novo = (POL*) malloc(sizeof(POL));
	novo->coef = coef;
    novo->pot = grau;

	if(POLVazia(P)){
    	novo->prox = P;
    	novo->ant = NULL;
    	return novo;
	}

	while(P->prox != NULL){

		if(novo->pot == P->pot){  //se a potencia do novo for igual a um elemento da POL
			P->coef =+ novo->coef;
			return P;
		}

		P = P->prox;
	}
	//nao existe coeficiente igual
	if(novo->pot < P->pot){ //insere primeira posicao
		novo->prox = P;
		novo->ant = NULL;
		P->ant = novo;
		return P;
	}

	else{
		POL *aux = P;
		while( (aux->prox != NULL) && (novo->pot > aux->prox->pot) ){
		    aux = aux->prox;
		}

		novo->prox = aux->prox;
		novo->ant = aux;

		if(aux->prox != NULL)
		    aux->prox->ant = novo;         
		    aux->prox = novo;
		    }
		}

	return P;
}
