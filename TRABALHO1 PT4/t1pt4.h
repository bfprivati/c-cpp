#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int valor;
    struct lista *prox;
}LISTA;

typedef struct fila{  //FIFO
	LISTA *first;
	LISTA *last;
}FILA;

FILA* iniciar(){  //OK
	FILA *aux;
	aux=(FILA*)malloc(sizeof(FILA));
	aux->first = NULL;
	aux->last = NULL;
    return aux;
}

FILA* inserir(FILA *F, int num){    //OK
    LISTA *aux = (LISTA*)malloc(sizeof(LISTA));
    aux->valor = num;
    aux->prox = NULL;

    if(F->last == NULL){ //lista vazia, insere no começo
        F->first = aux;
        F->last = aux;
    }else{
        F->last->prox = aux;
        F->last = aux;
    }

    return F;
}

FILA* remover(FILA *F, int *elem){
    if(F->first != NULL){
        LISTA *aux = F->first;
        *elem = aux->valor;
        F->first = aux->prox;

        if(F->first == NULL)  //se fila vazia, fim = NULL
            F->last = NULL;

        free(aux);
        return F;

    }else{
        *elem = (int)NULL;
        return F;
    }
}

/*void imprimir(FILA *F){
    FILA *aux = F->first;

    while(aux->prox != NULL){
        printf("%d, ", aux->valor);
        aux = aux->prox;
    }
} */


void menu(){
	int opc, num, elem;

	FILA *F, *F2, *F3, *F4;
	F = iniciar();
	F2 = iniciar();
	F3 = iniciar();
	F4 = iniciar();

	do{
        printf("1 - Inserir Elemento\n2 - Exibir Filas\n3 - Sair\n");
        scanf("%d", &opc);
        system("cls");

		switch(opc){

            case 1:     printf("Inserir elemento\n\n");
                        printf("Digite o valor a ser inserido: ");
                        scanf("%d", &num);
                        if(num == 0){
                            printf("Valor invalido\n");
                        }
                        else
                            F = inserir(F, num);
                        system("cls");
            break;
            case 2:     printf("Fila original: ");
                        //int elem;
                        F = remover(F, &elem);
                        while(elem != 0){
                            printf("%d ", elem);
                            if(elem%2 == 0){
                                inserir(F2, elem);
                            }
                            if(elem%3 == 0){
                                inserir(F3, elem);
                            }
                            if( (elem%2 != 0) && (elem%3 != 0) ){
                                inserir(F4, elem);
                            }

                            F = remover(F, &elem);
                        }
                        printf("\n\nFila com multiplos de 2: ");
                        F2 = remover(F2, &elem);
                        while(elem != 0){
                            printf("%d ", elem);
                            F2 = remover(F2, &elem);
                        }
                        printf("\n\nFila com multiplos de 3: ");
                        F3 = remover(F3, &elem);
                        while(elem != 0){
                            printf("%d ", elem);
                            F3 = remover(F3, &elem);
                        }
                        printf("\n\nFila com demais elementos: ");
                        F4 = remover(F4, &elem);
                        while(elem != 0){
                            printf("%d ", elem);
                            F4 = remover(F4, &elem);
                        }

                        getch();
                        system("cls");
			break;

			default:    if(opc == 3)
                            printf("Ate mais!\n");
                        else
                            printf("Opcao invalida!\n");
		}

	}while( opc != 3);

}
