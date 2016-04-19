#include<stdio.h>
#include<stdlib.h>

#define MAX 50

typedef struct pilha{
  char pilha[MAX];
  int topo;
}PILHA;

int pilhaCheia(PILHA *p); //OK
// retorna 1 se PILHA cheia, 0 caso contrário
int pilhaVazia(PILHA *p); //OK
// retorna 1 se PILHA vazia, 0 caso contrário
PILHA* criaPilha(PILHA *p); //OK
// inicializa uma PILHA
PILHA* push(PILHA *p, char elem); //OK
// emPILHA um elemento
int pop(PILHA *p);
// desemPILHA um elemento
void liberaPilha(PILHA *Ptp); //OK
// esvazia a PILHA
void menu(PILHA *p);  //OK, VER POP
//mostra o menu do programa

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

PILHA* criaPilha(PILHA *p){  //OK
  p->topo=0;
  return p;
}

PILHA* push(PILHA *p, char v){   //OK
  if (p->topo >= MAX){   //OVERFLOW
    printf("Overflow\n");
    return;
  }

  p->pilha[p->topo] = v;
  p->topo++;

  return;
}

int pop(PILHA *p){
  if(pilhaVazia(p))  //UNDERFLOW
    return 0;

  //*elem = (p->pilha[p->topo-1]);
  p->topo--;
  return 1;
}

void liberaPilha(PILHA *Ptp){ //OK
  Ptp->topo = -1;
  return;
}

void menu(PILHA *p){    //OK
  char ins;

  printf("Para ver se a expressao esta correta, digite -1");
  printf("Digite a expressao desejada:");

  do{
    scanf("%s", &ins);

    if(ins == '('){
      push(p, ins);
    } else
    if(ins == ')'){
        if(pilhaVazia(p)){
          printf("A expressao viola a 2 condicao");
          return;
        } else
        pop(p);
      }

  }while(ins != -1);

  if(pilhaVazia(p))
    printf("A expressao esta correta!");
  else
    printf("A expressao viola a 1 condicao");

    return;
}
