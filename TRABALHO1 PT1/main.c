//ARQUIVO CONTENDO MAIN

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"t1pt1.h"


int main(){
	int opc;

	LISTA *L;
	criarLista(L);  //inicializa lista

	do{
		printf("1 - Inserir Produto\n2 - Remover Produto\n3 - Trocar Produtos\n4 - Buscar Produto\n5 - Efetuar Compra\n 6 - Mostrar Produtos\n\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opc);

		menu(L, opc);

	}while(opc != 7);
	
	
	return 0;
}
