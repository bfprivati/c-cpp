#include<stdio.h>
#include<stdlib.h>

typedef struct polinomio{
	int coef;
	int pot;
	struct polinomio *prox, *ant;
}POL;

POL* criarPol(){   //OK, FUNCIONANDO
    return NULL;
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
    novo->ant = NULL;
    novo->prox = NULL;

	if(listaVazia(P)){
    	novo->prox = P;
    	novo->ant = NULL;
        printf("Lista vazia: %dx^%d\n", novo->coef, novo->pot);
        return novo;
	} else {

        POL *aux = P;
        while(aux->prox != NULL){     //verificar se existe potencia igual
            if(novo->pot == aux->pot){
                printf("coef igual\n");
                P->coef =+ novo->coef;
                return P;
            }
            aux = aux->prox;
        }

        //nao existe coeficiente igual
        if(novo->pot < P->pot){ //insere primeira posicao
            novo->prox = P;
            novo->ant = NULL;
            P->ant = novo;
            printf("Inserir primeira posicao: %dx^%d\n", novo->coef, novo->pot);
            return novo;
        } else {
            POL *aux = P;
            while( (aux->prox != NULL) && (novo->pot > aux->prox->pot) ){
                aux = aux->prox;
            }

            printf("Inserir ultima: %dx^%d\n", novo->coef, novo->pot);
            novo->prox = aux->prox;         //inserir ultima posicao
            novo->ant = aux;

            if(aux->prox != NULL){ //insere ultima
                printf("Inserir meio: %dx^%d\n", novo->coef, novo->pot);
                aux->prox->ant = novo;
            }
            else
                aux->prox = novo;
        }
	}

    return P;
}

void imprimeLista(POL *P){
	if(listaVazia(P)){
        printf("Lista vazia!\n");
		return;
	} else{

        POL *aux = P;

        while(aux != NULL){
            aux = aux->prox;
            if(aux == NULL){
                while(aux != NULL){
                printf("%dx^%d\n", P->coef, P->pot);
                aux = aux->ant;
                }
            }
        }
	}
}

void menu(){
    int ins;
    int coef, pot;

    POL *P;
    P = criarPol();

	do{
        printf("1 - Inserir nova expressao\n2 - Imprimir P(x)\n3 - Sair\n");
        scanf("%d", &ins);

        switch(ins){
            case 1:     printf("Digite o coef: ");
                        scanf("%d", &coef);
                        printf("Digite o grau: ");
                        scanf("%d", &pot);
                        P = inserir(P, coef, pot);
            break;

            case 2:     imprimeLista(P);
            break;

            default:    if(ins == 3)
                            printf("Ate mais!");
                        else
                            printf("Opcao invalida!");
        }

	}while(ins != 3);
}
