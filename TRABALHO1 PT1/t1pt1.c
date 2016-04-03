//ARQUIVO COM FUNÇÕES

#include<stdio.h>
#include<stdlib.h>
#include"t1pt1.h"

#define MAX 50  

typedef struct produto{  
	int codProd;  //código do produto  
	char nomeProd[10]; //nome do produto  
	float valor;  //valor do produto  
	int qtdeEstoque; //quantidade disponível em estoque 
}PRODUTO;

// typedef struct produto Produto;   DEFINIDO ACIMA  

typedef struct lista{   
	PRODUTO dados[MAX]; //arranjo com os elementos da lista   
	int FL;  // índice da primeira posição livre da lista (ou seja, fim da lista) 
}LISTA;  

// typedef struct Lista Lista;   DEFINIDO ACIMA 

void criarLista(LISTA *L){   //OK
	L->FL = -1;    //cria uma lista vazia, começando do elemento nulo
}

int inserirProduto(LISTA *L, PRODUTO p){   //  OK, REVER ORDENAÇÃO
	int i, j, aux;  //variavel que recebera a troca de elementos

	if(L == NULL){   //se não foi inicializada 
		printf("Lista nao inicializada!");
		return 0;  //insucesso
	}

	if(L->FL == MAX){  //Se a ultima posição for igual ao MAX, a fila esta cheia
		printf("Lista Cheia!");
		return 0;  //insucesso
	}

	L->FL ++;  //se estiver inicializada e não estiver cheia, a posição do elemento é atualizada
	L->dados[L->FL] = p;  //se não estiver cheia, a primeira posicao livre recebe o novo

	for(i = 0; i <= L->FP ; i++){  //verificar se o codigo já existe
		if( (L->dados[L->FL].codProd) == (L->dados[i].codProd) ){
			printf("Codigo do produto ja cadastrado! Essa insercao foi desconsiderada\n");
			L->LF -- ;
			return 0;  //insucesso 
		}
	}

	//ordenar o vetor
	for(i = 1; i <= L->FL; i++){  // Ordenando o vetor com Insert Sort REVER
		L->dados[L->FL] = L->dados[i];
		j = i - 1 ;

		while( (j >= 0) && (L->dados[FL].codProd > L->dados[i].codProd) ){
			L->dados[j + 1] = L->dados[j];
			j --;
		}

		L->dados[j + 1] = L->dados[L->LF];
	}

	return 1;  //inclusao bem sucedida
}

int removerProduto(LISTA *L, int n){	//OK
	int i, j;

	if(n > L->FL){
		L->FL = -1;
		return L;
	}

	j = 0;
	i = n+1;

	for(L->dados[i]; i = L->dados[LF]; i++){
		L->dados[j] = L->dados[i];
		j++;
	}

	L->FL = j;

	return L;
}

int trocaProduto(LISTA *L, int pos1, int pos2){

}

int buscaProduto(LISTA *L){  //OK, MAS VERIFICAR 
	int pos; 

	if( (L == NULL) || (L->FL == -1) ) //se não foi inicializada ou vazia 
		printf("Lista Vazia!");
		return 0;  //insucesso
	}

	PRODUTO menorEstoque;  //variavel para ajudar na busca

	menorEstoque = L->dados[0];   //variavel recebe o primeiro elemento da lista

	for(i=0; i<=L->FL; i++){
		if( L->dados[i].qtdeEstoque < menorEstoque->qtdeEstoque ){
			menorEstoque = L->dados[i];
			pos = i;
		}
	}

	return pos;
}

int efetuarCompra(LISTA *L, int codProd, int qtde){

}

void imprimeLista(LISTA *L){    //OK
	int i;

	if( (L == NULL) || (L->FL == -1) ) //se não foi inicializada ou vazia 
		printf("Lista Vazia!");
		return 0;  //insucesso
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