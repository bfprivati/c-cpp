#include<stdio.h>
#include<stdlib.h>
#include"t1pt3.h"

#define Max 50  

typedef struct pilha{     
  char pilha[MAX];      
  int topo; 
}PILHA; 

int pilhaCheia(PILHA *p){ //OK
  if(p->topo == MAX)
    return 1;
  else
    return 0;
}

int pilhaVazia(PILHA *p){ //OK
  if(p->topo == 0)
    return 1;
  else
    return 0;
}

void criaPilha(PILHA *p){  //OK
  p->topo=0;
}

void push(PILHA *p, int v){   //OK
  if (p->topo >= MAX){   //OVERFLOW
    printf("Overflow\n");
    return;
  }

  p->v[p->topo] = v;
  p->topo++;

  return;
}

int pop(PILHA *p, int *elem){
  if(p->topo == 0)  //UNDERFLOW
    return 0;

  *elem = (p->v[p->topo-1]);
  p->topo--;
  return 1;
}

void liberaPilha(PILHA *Ptp){ //OK
  Ptp->topo = -1;
  return;
}

void menu(PILHA *p){    //OK
  int ins;

  printf("Para ver se a expressao esta correta, digite "=1" ");
  printf("Digite a expressao desejada:")

  do{

    scanf("%s", &ins);

    if(ins == '('){
      push(&p; ins);
    } else
    if(ins == ')'){
        if(pilhaVazia(&p)){
          printf("A expressao viola a 2 condicao");
          return;
        } else
        pop(&p; ins);
      }

  }while(ins != -1);

  if(pilhaVazia(&p))
    printf("A expressao esta correta!");
  else
    printf("A expressao viola a 1 condicao");

  return;
}