#include<stdio.h>
#include<stdlib.h>

typedef struct fila{  //FIFO
	int valor;
	struct fila *prox, *first, *last;
}FILA;

FILA* iniciar(){  //OK
	FILA *aux;
	aux=(FILA*)malloc(sizeof(FILA));
	aux->first = NULL;
	aux->last = NULL;

}

FILA* inserir(FILA *F, int num){    //OK
    FILA *aux = (FILA*)malloc(sizeof(FILA));
    aux->valor = num;
    aux->prox = NULL;
    printf("adicionou elemento");

    if(F->last == NULL){ //inserir começo
        F->first = aux;
        F->last = aux;
        printf("inseriu primeiro elemento\n");
    }else{
        F->last->prox = aux;
        F->last = aux;
        printf("inseriu fim");
    }
    return F;
}

/*void imprimir(FILA *F){

} */


void menu(){
	int opc, num;

	FILA *F, *F2, *F3, *F4;
	F = iniciar();
	F2 = iniciar();
	F3 = iniciar();
	F4 = iniciar();

	while(opc!=3){
        printf("1 - Inserir Elemento\n2 - Exibir Filas\n3 - Sair\n");
        scanf("%d", &opc);

		switch(opc){

			case 1:		printf("Inserir elemento\n");
						printf("Digite o elemento a ser inserido: ");
						scanf("%d", &num);

                        F = inserir(F, num);

                        if( (num%2 == 0) && (num%3 == 0) ){
                            printf("f2 e f3\n");
                            F2 = inserir(F2, num);
                            F3 = iniciar(F3, num);
                        } else
                        if( (num%2 == 0) && (num%3 != 0) ){
                            printf("f2\n");
                            F2 = inserir(F2, num);
                        } else
                        if( (num%2 != 0) && (num%3 == 0) ){
                            printf("f3\n");
                            F3 = inserir(F3, num);
                        } else
                        if( (num%2 != 0) && (num%3 != 0) ){
                            printf("f4\n");
                            F4 = inserir(F4, num);
                        }
			break;
			/*
			case 2:	    printf("Fila original: \n");
                        imprimir(F);
                        printf("\n\nFila com multiplos de 2: \n");
                        imprimir(F2);
                        printf("\n\nFila com multiplos de 3: \n");
                        imprimir(F3);
                        printf("\n\nFila com demais elementos: \n");
                        imprimir(F4);
			break;   */
			default:    if(opc == 3)
                            printf("Ate mais!\n");
                        else
                            printf("Opcao invalida!\n");
		}

	}

}
