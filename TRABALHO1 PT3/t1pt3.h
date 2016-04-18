#include<stdio.h>
#include<stdlib.h>

typedef struct pilha PILHA;

int pilhaCheia(PILHA *p); //OK
// retorna 1 se PILHA cheia, 0 caso contrário
int pilhaVazia(PILHA *p); //OK
// retorna 1 se PILHA vazia, 0 caso contrário
void criaPilha(PILHA *p); //OK
// inicializa uma PILHA
void push(PILHA *p, char elem); //OK
// emPILHA um elemento
int pop(PILHA *p);
// desemPILHA um elemento
void liberaPilha(PILHA *Ptp); //OK
// esvazia a PILHA
void menu();  //OK, VER POP
//mostra o menu do programa
