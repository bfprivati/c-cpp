#include<stdio.h>
#include<stdlib.h>

#define MAX 50

typedef struct pilha{
  char pilha[MAX];
  int topo;
}PILHA;

void criaPilha(PILHA *p){  //OK
  p->topo=0;
}

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

void push(PILHA *p, char v){   //OK
  if (pilhaCheia(p))   //OVERFLOW
    return;

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

void menu(){    //OK
  char ins, opc, msg;
  PILHA *p;
  criaPilha(&p);

  do{
    printf("Para acrescentar uma nova expressao, digite 1. Para sair, digite -1\n");
    scanf("%d", &opc);
    system("cls");
    if(opc == 1){

        printf("Para ver se a expressao esta correta, digite s\n");
        printf("Digite a expressao desejada:\n");

        while(ins != 's'){
            msg=0;
            scanf("%s", &ins);

            if(ins == '('){
            push(&p, ins);
            } else
            if(ins == ')'){
                if(pilhaVazia(&p) == 1){
                  printf("A expressao viola a 2 condicao\n\n");
                  getch();
                  system("cls");
                  msg = 1;
                  ins = 's';
                } else
                pop(&p);
              }
          }

          if(pilhaVazia(&p) == 1 && msg == 0){
            printf("A expressao esta correta!\n\n");
            getch();
            system("cls");
          }
          else
            if(pilhaVazia(&p) != 1 && msg == 0){
            printf("A expressao viola a 1 condicao\n\n");
            getch();
            system("cls");
            }
    }

  }while(opc!= -1);

  printf("Ate mais!");
}
