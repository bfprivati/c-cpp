#include <stdlib.h>
#include <stdio.h>
#include "t1pt2.h"
main(){
	int opc,n,result;
	POL *E = NULL;

	do{
		system("cls");
		menu();
		printf("\nDigite a opcao desejada: ");
		scanf("%d",&opc);
        system("cls");
		switch(opc){
            case 1:
                        inserir(&E);
            break;
            case 2:
                        destruir(&E);
                        printf("Polinomio reicializado!\n");
                        system("pause");
            break;
            case 3:
                        system("cls");
                        if(listaVazia(&E)==1){
                            printf("Lista Vazia!");
                            getch();
                        }else{
                        printf("Digite o expoente do elemento que vc deseja remover: ");
                        scanf("%d",&n);
                        remover(&E,n);
                        }
            break;
            case 4:     printf("Calcular P(x)\n\n");
                        printf("Digite um valor para x : ");
                        scanf("%d",&n);
                        result = calculo(E,n);
                        printf("X = %d\n",result);
                        system("pause");
            break;
            case 5:
                        imprimir(E);
            break;
            default:    if(opc == 6)
                            printf("Ate mais!\n");
                        else
                            printf("Opcao invalida!");
		}

	}while(opc != 6);

}
