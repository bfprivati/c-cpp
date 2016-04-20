#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct produto{
	int codProd;  //código do produto
	char nomeProd[10]; //nome do produto
	float valor;  //valor do produto
	int qtdeEstoque; //quantidade disponível em estoque
}PRODUTO;

typedef struct lista{
	PRODUTO dados[MAX]; //arranjo com os elementos da lista
	int FL;  // índice da primeira posição livre da lista (ou seja, fim da lista)
}LISTA;

void criarLista(LISTA *L){   //OK
	L->FL = -1;    //cria uma lista vazia, começando do elemento nulo
}

int listaCheia(LISTA *L){ //OK
  if(L->FL == MAX)
    return 1;
  else
    return 0;
}

int listaVazia(LISTA *L){ //OK
  if(L->FL == -1)
    return 1;
  else
    return 0;
}

int inserirProduto(LISTA *L, PRODUTO *p){   //  OK, REVER ORDENAÇÃO
	int i, j, aux;  //variavel que recebera a troca de elementos

	if(L == NULL){   //se não foi inicializada
		printf("Lista nao inicializada!");
		return 0;  //insucesso
	}

	if(listaCheia(&L)==1){
		printf("Lista Cheia!");
		return 0;  //insucesso
	}

	L->FL ++;  //se estiver inicializada e não estiver cheia, a posição do elemento é atualizada
	L->dados[L->FL] = *p;  //se não estiver cheia, a primeira posicao livre recebe o novo

	for(i = 0; i <= L->FL ; i++){  //verificar se o codigo já existe
		if( (L->dados[L->FL].codProd) == (L->dados[i].codProd) ){
			printf("Codigo do produto ja cadastrado! Essa insercao foi desconsiderada\n");
			L->FL -- ;
			return 0;  //insucesso
		}
	}

	//ordenar o vetor
	for(i = 1; i <= L->FL; i++){  // Ordenando o vetor com Insert Sort REVER
		L->dados[L->FL] = L->dados[i];
		j = i - 1 ;

		while( (j >= 0) && (L->dados[L->FL].codProd > L->dados[i].codProd) ){
			L->dados[j + 1] = L->dados[j];
			j --;
		}

		L->dados[j + 1] = L->dados[L->FL];
	}

	return 1;  //inclusao bem sucedida
}

int removerProduto(LISTA *L, int n){	//OK
	int i, j;

	if(n > L->FL){
		L->FL = -1;
		return 1;
	}

	j = 0;

	for(i=0; i = n; i++){
        L->dados[i] = L->dados[n+i];
        j++;
        if(n+i > L->FL)
            j--;
    }

	L->FL = j;

	return 1;
}

int trocaProduto(LISTA *L, int pos1, int pos2){	//OK
	char aux;

	if( (L == NULL) || (L->FL == -1) ){ //se não foi inicializada ou vazia
		printf("Lista Vazia!");
		return 0;  //insucesso
	}

	if( (pos1 || pos2) > L->FL){ //um dos dois nao esta na lista
		printf("Uma das posicoes inseridas nao consta na lista");
        return 0;
	}

	if( (pos1 || pos2) < -1){  //um dos dois nao esta na lista
        printf("Uma das posicoes inseridas nao consta na lista");
		return 0;
	}

	strcpy(aux, L->dados[pos1].nomeProd);
	strcpy(L->dados[pos1].nomeProd, L->dados[pos2].nomeProd);
	strcpy(L->dados[pos2].nomeProd, aux);

	return 1;
}

int buscaProduto(LISTA *L){  //OK, MAS VERIFICAR
	int pos=0, i=0, j=0;

	if( (L == NULL) || (L->FL == -1) ){ //se não foi inicializada ou vazia
		printf("Lista Vazia!");
		return 0;  //insucesso
	}

	LISTA *menorEstoque;  //variavel para ajudar na busca

	for(i=0; i<= L->FL; i++){
		if( L->dados[i].qtdeEstoque < menorEstoque->dados[j].qtdeEstoque ){
			menorEstoque->dados[j] = L->dados[i];
			pos = i;
		}
	}

	mostrarElemento(&L, pos);

	return 1;
}

int efetuarCompra(LISTA *L, int codProd, int qtde){  //OK
    int i;

	for(i=0; i<=L->FL; i++){
		if(codProd == L->dados[i].codProd){

			if(qtde < L->dados[i].qtdeEstoque){   //estoque nao suficiente
				printf("Estoque Insuficiente!");
				return 0;
			}

			L->dados[i].qtdeEstoque =- qtde;  //decrementa estoque
			return 1;

		} else {
			printf("Produto nao encontrado!");
			return 0;
		}

	}

	return 1;
}

void imprimeLista(LISTA *L){    //OK
	int i;

	if( (L == NULL) || (L->FL == -1) ){ //se não foi inicializada ou vazia
		printf("Lista Vazia!");
		return;  //insucesso
	}

	PRODUTO produto;  //variavel para ajudar no printf

	for(i=0; i<=L->FL; i++){

		produto = L->dados[i];

		printf("Codigo do Produto: %d \n", produto.codProd);
		printf("Nome do Produto: %s \n", produto.nomeProd);
		printf("Valor do Produto: %f \n", produto.valor);
		printf("Quantidade em Estoque: %d \n", produto.qtdeEstoque);
	}
}

void mostrarElemento(LISTA *L, int pos){

		printf("O produto que tem a menor quantidade em estoque:\n\n ");

		printf("Codigo do Produto: %d \n", L->dados[pos].codProd);
		printf("Nome do Produto: %s \n", L->dados[pos].nomeProd);
		printf("Valor do Produto: %f \n", L->dados[pos].valor);
		printf("Quantidade em Estoque: %d \n", L->dados[pos].qtdeEstoque);
}

void menu(){
	int opc;
	int n, pos1, pos2, codProd, qtde;

    PRODUTO *P;
	LISTA L;
    criarLista(&L);

	do{
		printf("1 - Inserir Produto\n2 - Remover Produto\n3 - Trocar Produtos\n4 - Buscar Produto\n5 - Efetuar Compra\n6 - Mostrar Produtos\n\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opc);

        system("cls");

			switch(opc){
			case 1: printf("Inserir Produtos\n\n");
					printf("Digite o codigo do produto: ");
					scanf("%d", &P->codProd);
					printf("\nDigite o nome do produto: ");
					scanf("%s", &P->nomeProd);
					printf("\nDigite o valor do produto: ");
					scanf("%f", &P->valor);
					printf("\nDigite a quantidade a ser estocada: ");
					scanf("%d", &P->qtdeEstoque);
					inserirProduto(&L, &P);
			break;
			case 2: printf("Remover Produtos\n");
                    if( listaVazia(&L) == 1 ){ //se não foi inicializada ou vazia
                        printf("Lista Vazia!\n\n");
                    } else {
                        printf("Digite a quantidade de elementos a serem retirados: ");
                        scanf("%d", &n);
                        removerProduto(&L, n);
                    }
			break;
			case 3:	printf("Trocar Produtos\n\n");
					printf("Digite as posicoes a serem trocadas\n");
					printf("Posicao 1: ");
					scanf("%d", &pos1);
					printf("\nPosicao 2: ");
					scanf("%d", &pos2);
					trocaProduto(&L, pos1, pos2);
			break;
			case 4:	printf("Buscar Produtos\n\n");
					buscaProduto(&L);
			break;
			case 5:	printf("Efetuar Compra\n\n");
					printf("Digite o codigo do produto: ");
					scanf("%d", &codProd);
					printf("\nDigite a quantidade a ser comprada: ");
					scanf("%d", &qtde);
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


	}while(opc != 7);

	return;
}
