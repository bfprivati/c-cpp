#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define Max 50
int fimLista =-1;

typedef struct produto{
	int codProd;
	char nomeProd[10];
	float valor;
	int qtdeEstoque;
}PRODUTO;

typedef struct  lista{
	PRODUTO dados[Max];
}LISTA;

void menu(){
	system("cls");
	printf("1 - Inserir Elemento\n");
	printf("2 - Remover 'n' Elementos\n");
	printf("3 - Exibir Lista\n");
	printf("4 - Trocar elementos\n");
	printf("5 - Produto com o menor estoque\n");
	printf("6 - Sair\n");
	printf("\nDigite um comando: ");
}

PRODUTO novoProduto(){
	PRODUTO novo;
	system("cls");
	printf("Digite o codigo do produto: ");
	scanf("%d",&novo.codProd);
	printf("\nDigite o nome do Produto: ");
	scanf("%s",&novo.nomeProd);
	printf("\nDigite o valor do produto: ");
	scanf("%f",&novo.valor);
	printf("\nQtd no Estoque: ");
	scanf("%d",&novo.qtdeEstoque);

	return novo;
}

int cheia(int fimLista){
	if(fimLista+1==Max)
	{
		return 1;
	}else{
		return 0;
	}
}

int vazia(int fimLista){
	if(fimLista==-1){
		return 1;
	}else{
		return 0;
	}
}


int inserir(LISTA *estoque){
	int i,opc;
	PRODUTO aux,aux2;

	if(vazia(fimLista)==1){  //se lista vazia, insere na primeira posicao
		fimLista++;
		estoque->dados[fimLista] = (PRODUTO)novoProduto();
		return 1;
	}else
	if(cheia(fimLista)==1){
		printf("Lista cheia!\n");
		return 0;
	}else{
		i=0;
		opc=1;
		aux = novoProduto();
		fimLista++;
		do{
			if(estoque->dados[i].codProd>aux.codProd)
			{
				aux2=estoque->dados[i];
				estoque->dados[i]=aux;
				aux=aux2;
			}
			i++;
		}while(i!=fimLista);
		//inserir na lista e ordenar
		estoque->dados[fimLista] = aux;
		return 1;
    }
}

void remover(LISTA *estoque){
	int code,i=0;
	PRODUTO aux;
	if(vazia(fimLista)==1){
		printf("ERRO: Lista vazia, impossivel remoção\n");
	}else{
		//achar o elemento, excluir reordenar lista
		system("cls");
		printf("\n\nRemoção de produto\n");
		printf("Digite o codigo do produto: ");
		scanf("%d",&code);
		do{
			if(estoque->dados[i].codProd==code)
			{
				for(i;i<fimLista;i++)
				{
					estoque->dados[i] = estoque->dados[i+1];
				}
				fimLista--;
			}
			i++;
		}while(i!=fimLista);
	}
}

int removeN(LISTA *estoque,int n){
	int i=0;
	if(vazia(fimLista)==1){
		printf("ERRO: Lista vazia impossivel remover elementos\n");
		return 0;
	}else{
		if((fimLista+1)<=n){
			//ou destruo ou erro?
			fimLista=-1;
		}else{
			/*for(i=estoque->FL;i<n;i++)
			{
				estoque->FL++;
				//printf("FL= %d\n",estoque->FL);
			}*/
			for(i=n;i<=fimLista;i++){
				estoque->dados[i-n]=estoque->dados[i];
			}
			fimLista -= n;
		}
	}
}

void imprimirLista(LISTA *estoque){
	int i;
	if(vazia(fimLista)==1){
		system("cls");
		printf("Lista vazia!\n");
		getch();
	}else{
		system("cls");
		for(i=0;i<=fimLista;i++){
			printf("\nCod: %d\n",estoque->dados[i].codProd);
			printf("Produto: %s\n",estoque->dados[i].nomeProd);
			printf("Preco: %.2f\n",estoque->dados[i].valor);
			printf("Qtde: %d\n",estoque->dados[i].qtdeEstoque);
		}
		getch();
    }
}

int trocaProdutos (LISTA *estoque, int pos1, int pos2){
	char aux[10];
	if(vazia(fimLista)==1){
		printf("ERRO: no minimo dois produtos diferentes no estoque para a troca\n");
	}else
	if(fimLista==0){
		printf("ERRO: no minimo dois produtos diferentes no estoque para a troca\n");
	}else{
		if(0<=pos1<=fimLista && 0<=pos2<=fimLista){
			strcpy(aux,estoque->dados[pos1].nomeProd);
			strcpy(estoque->dados[pos1].nomeProd,estoque->dados[pos2].nomeProd);
			strcpy(estoque->dados[pos2].nomeProd,aux);
		}
	}
}



void imprime(LISTA *estoque,int code){
	int check=0,i;

	if(vazia(fimLista)==1){
		system("cls");
		printf("Lista vazia!\n");
	}else{
		for(i=0;i<=fimLista;i++)
		{
			if(estoque->dados[i].codProd==code){
				printf("\nCod: %d\n",estoque->dados[i].codProd);
				printf("Produto: %s\n",estoque->dados[i].nomeProd);
				printf("Preco: %.2f\n",estoque->dados[i].valor);
				printf("Qtde: %d\n",estoque->dados[i].qtdeEstoque);
				check=1;
			}
		}
		if (check==0){
			system("cls");
			printf("Codigo nao encontrado\n");
		}
	}
}

int buscar(LISTA *estoque,int codProd){
	int i=0,pos=-1;

	if(vazia(fimLista)==1){
		printf("Lista vazia\n");
		return pos;
	}else{
		pos = 0;
		do{
			if(estoque->dados[i].codProd==codProd){
				pos = i;
			}
			i++;
		}while(i!=fimLista);

		return pos;
	}
}

int efetuarCompra(LISTA *estoque, int codProd, int qtde){   //efetua compra de um produto
	int aux;
	if(vazia(fimLista)==1){
		printf("Lista vazia!\n");
		return 0;
	}else
	if(buscar(estoque,codProd)!=-1){
		aux = buscar(estoque,codProd);
		if(estoque->dados[aux].qtdeEstoque >= qtde){
			estoque->dados[aux].qtdeEstoque -= qtde;
			return 1;
		}else{
			printf("Quantidade em estoque insuficiente para compra\n");
			return 0;
		}
	}else{
		printf("Produto nao encontrado\n");
		return 0;
	}

}


int buscarProduto(LISTA *estoque){  //busca produto com menor estoque
	int i=0, aux, pos;

	if(vazia(fimLista)==1){
		printf("Lista vazia!\n");
		return 0;
	}else{
		pos = 0;
		aux = estoque->dados[pos].qtdeEstoque;
		do{
			if(aux > estoque->dados[i].qtdeEstoque){
				pos = i;
				aux = estoque->dados[i].qtdeEstoque;
			}
			i++;
		}while(i<fimLista);

		return pos;
	}
}


