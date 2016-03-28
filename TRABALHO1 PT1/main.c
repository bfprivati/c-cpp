//ARQUIVO CONTENDO MAIN

#include<stdio.h>
#include<stlib.h>
#include"t1pt1.h"


int main(){
	int opc;

	LISTA L;
	criarLista(&L);  //inicializa lista
	PRODUTO p;

	do{
		printf("1 - Inserir Produto\n2 - Remover Produto\n3 - Trocar Produtos\n4 - Buscar Produto\n5 - Efetuar Compra\n 6 - Mostrar Produtos\n\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opc);

		system("cls");

		switch(opc){
			case 1: printf("Inserir Produtos\n\n");
					inserirProduto(&L, p);
			break;
			case 2: printf("Remover Produtos\n\n");
					removerProduto(&L, n);
			break;
			case 3:	printf("Trocar Produtos\n\n");
					trocaProduto(&L, pos1, pos2);
			break;
			case 4:	printf("Buscar Produtos\n\n");
					buscaProduto(&L, int *pos, PRODUTO *MenorEstoque);
			break;
			case 5:	printf("Efetuar Compra\n\n");
					efetuarCompra(&L, codProd, qtde);
			break;	
			case 6:	printf("Mostrar Produtos\n\n");
					imprimeLista(&L);
			break;
			default: 	if(opc == 7)
							printf("Ate Mais!");
						else
							printf("Opcao invalida!");
		}
		
		system("cls");

	}while(opc != 7);

	return 0;
}