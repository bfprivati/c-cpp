#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct polinomio{
	int expoente;
	int num;
	struct polinomio *prox;
}POL;

int listaVazia(POL **E){
    if(*E == NULL)
        return 1;
    else
        return 0;
}

POL *novo(int expo,int n){
	POL *novo = malloc(sizeof(POL));
    novo->expoente = expo;
    novo->num = n;
    novo->prox = NULL;
    return novo;
}

void destruir(POL **E){ //OK
	if(!(*E))
		return;
	destruir(&(*E)->prox);
	free(*E);
	*E = NULL;
}

void imprimir(POL *E){
    printf("Imprimir polinomio\n\n");

	POL *P;
	if(listaVazia(&E)==1){
		printf("Lista Vazia!\n");
		getch();
	}else{
		P = E;
		printf("P(x) = ");
		while(P != NULL){
			if(P->expoente==0){
				if(P->num>0){
					printf(" +%d ",P->num);
				}else{
					printf(" %d ",P->num);
				}
			}else if(P->num>0){
				printf(" +%dx^%d ",P->num,P->expoente);
			}else{
				printf(" %dx^%d ",P->num,P->expoente);
			}
			P=P->prox;
		}
		printf("\n");
		getch();
	}
}

void inserir(POL **E){
    printf("Inserir termo no polinomio\n\n");

	int pot, coef , opc=0;
	POL *elem;
	POL *P;
	printf("Digite o coeficiente :");
	scanf("%d",&coef);
	printf("Digite a potencia: ");
	scanf("%d",&pot);
	elem = novo(pot, coef);

	if(*E==NULL){
		*E = elem;
	}else{
		P = *E;

		if(P->expoente>=elem->expoente){
			if(P->expoente==elem->expoente){
				P->num += elem->num;
			}else{
				elem->prox = P;
				P = elem;
				*E = P;
			}
		}else{
			while((P->prox!=NULL) && P->prox->expoente<=elem->expoente && opc==0){ //p->next->expoente<elem->expoente)
				//if(p->next->expoente<elem->expoente)
				if(P->prox->expoente==elem->expoente){
					P->prox->num += elem->num;
					opc = 1;
				}
				P = P->prox;
			}
			if(opc!=1){
				elem->prox = P->prox;
				P->prox = elem;
			}
		}
	}
}

void remover(POL **E,int n){
    printf("Retirar elemtno com a potencia N\n\n");

	POL *aux,*P;

		P=*E;
		if(P->expoente==n){
			aux = (P)->prox;
			free(P);
			P = aux;
			*E = P;

		}else{
			P=*E;
			while(P->prox!=NULL){
				if(P->prox->expoente==n){
					aux = P->prox;

					if(aux->prox==NULL){
						P->prox=NULL;
					}else{
						P->prox = aux->prox;
					}
					free(aux);

				}else{
					P = P->prox;
				}

			}
		}
}

int calculo(POL *E,int x){  //OK
	POL *P = E;
	int result=0;
	if(listaVazia(&P)==1){
		return 0;
	}else{
		return P->num*pow(x,P->expoente) + calculo(P->prox,x);
	}
}

void menu(){
	printf("1 - Insira termo no polinomio\n");
	printf("2 - Reinicializar polinomio\n");
	printf("3 - Retirar elemento com a potencia N\n");
	printf("4 - Calcular P(x)\n");
	printf("5 - Imprimir polinomio\n");
	printf("6 - Sair\n");
}
