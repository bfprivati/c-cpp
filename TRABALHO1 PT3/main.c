#include<stdio.h>
#include<stdlib.h>
#include"t1pt3.h"

int main(){
	int opc=0;

	PILHA *p;

	do{
		printf("Para acrescentar uma nova expressao, digite 1. Para sair, digite -2\n");
		scanf("%d", &opc);

		if(opc == 1){
			criaPilha(p);
			menu(p);
		}

	}while(opc =! -2);

	return 0;
}
