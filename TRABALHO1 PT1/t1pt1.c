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

int inserirProduto(LISTA *L, PRODUTO p){
	
}

int removerProduto(LISTA *L, int n){

}

int trocaProduto(LISTA *L, int pos1, int pos2){

}

int buscaProduto(LISTA *L, int *pos, PRODUTO *MenorEstoque){

}

int efetuarCompra(LISTA *L, int codProd, int qtde){

}

void imprimeLista(LISTA *L){    //OK
	int i;

	PRODUTO produto;  //variavel para ajudar no printf

	for(i=0; i<=L->FL; i++){

		produto = L->dados[i];

		printf("Codigo do Produto: %d \n", produto.codProd); 
		printf("Nome do Produto: %s \n", produto.nomeProd);
		printf("Valor do Produto: %f \n", produto.valor);
		printf("Quantidade em Estoque: %d \n", produto.qtdeEstoque);
	}
}