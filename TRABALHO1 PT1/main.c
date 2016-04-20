#include <stdlib.h>
#include <stdio.h>
#include "t1pt1.h"

int main(void){
	int opc=0,n,pos1,pos2,y;
	LISTA estoque;

	do{
		menu();
		scanf("%d",&opc);
		switch(opc){
            case 1:
                        inserir(&estoque);
            break;
            case 2:
                        printf("Quantos elementos deseja remover? \n");
                        scanf("%d",&n);
                        y = removeN(&estoque,n);
                        if(y){
                            printf("Remocao realizada com sucesso!\n");
                        }else{
                            printf("Remocao nao realizada\n");
                        }
            break;
            case 3:
                        imprimirLista(&estoque);
            break;
            case 4:
                        printf("Insira as posicoes a serem trocadas:\nPos 1: ");
                        scanf("%d",&pos1);
                        printf("Pos 2: ");
                        scanf("%d",&pos2);
                        trocaProdutos(&estoque,pos1,pos2);
            break;
            case 5:
                        system("cls");
                        printf("Produto com a menor quantidade em estoque:\n\n");
                        y=buscarProduto(&estoque);
                        printf("\nCod: %d\n",estoque.dados[y].codProd);
                        printf("Produto: %s\n",estoque.dados[y].nomeProd);
                        printf("Preco: %.2f\n",estoque.dados[y].valor);
                        printf("Qtde: %d\n",estoque.dados[y].qtdeEstoque);
                        getch();
            break;
            default:    if(opc == 6)
                            printf("Ate mais!\n");
                        else
                            printf("Opcao invalida!\n");
		}
	}while(opc!=6);

	return 0;
}
