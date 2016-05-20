#include <stdio.h>
#include <stdlib.h>
#define MAX 100


typedef struct arv
{
    int elem;
    struct arv *esq;
    struct arv *dir;
} Arv;



typedef struct fila
{
    Arv *v[MAX];
    int qtde;
    int ini;
} Fila;


void iniciar(Fila *p)
{
    p->ini = 0;
    p->qtde = 0;
}


void inserir_fila(Fila *p, Arv *v)
{

    if(fila_cheia(p)==0)
    {
        int fim = (p->ini+p->qtde)%MAX;
        p->v[fim] = v;
        p->qtde++;
    }
    else
    {
        printf("\nFila Cheia!\n");
    }
}

Arv* remover_fila(Fila *f)
{

    Arv *aux = NULL;
    if(fila_vazia(f) == 0)
    {
        aux = f->v[f->ini];
        f->ini = (f->ini+1)%MAX;
        f->qtde--;
    }
    return aux; // se fila vazia
}

int fila_cheia(Fila *f)
{

    if( f->qtde == MAX)
        return 1;
    else
        return 0;

}


int fila_vazia(Fila *f)
{

    if(f->qtde == 0)
        return 1;
    else
        return 0;

}



void preordem(Arv *raiz)
{
    if (raiz != NULL)
    {
        printf("%d.", raiz->elem);
        preordem(raiz->esq);
        preordem(raiz->dir);
    }
}

void emordem(Arv *raiz)
{
    if (raiz != NULL)
    {
        emordem(raiz->esq);
        printf("%d.", raiz->elem);
        emordem(raiz->dir);
    }
}

void posordem(Arv *raiz)
{
    if (raiz != NULL)
    {
        posordem(raiz->esq);
        posordem(raiz->dir);
        printf("%d.", raiz->elem);
    }
}



Arv* arv_cria(int dado, Arv *esq, Arv *dir)
{
    Arv* p=(Arv*)malloc(sizeof(Arv));
    p->elem = dado;
    p->esq = esq;
    p->dir = dir;
    return p;
}


Arv* inserir(Arv* raiz, int elem)
{
   if (raiz == NULL)
   {
      return arv_cria(elem,NULL,NULL);
   }
   else
   {
      if(elem < raiz->elem)
          raiz->esq = inserir(raiz->esq, elem);
      else
          raiz->dir = inserir(raiz->dir, elem);
   }
   return raiz;

}


Arv* remover(Arv* raiz, int elem)
{

}

void imprime_largura(Arv *raiz){
    Arv* aux;

    Fila fila;
    iniciar(&fila);
    if (raiz!=NULL){
        inserir_fila(&fila, raiz);
        while(fila_vazia(&fila)==0){
            aux = remover_fila(&fila);
            printf("%d.", aux->elem);
            if(aux->esq!=NULL)
                inserir_fila(&fila, aux->esq);
            if(aux->dir!=NULL)
                inserir_fila(&fila, aux->dir);
        }
    }    
    else
        printf("Arvore vazia!\n");
}




int main ()
{

    Arv *a = NULL;
    int op;
    scanf("%d",&op);

    while(op != -1)
    {
        if(op == 1)
        {
            int elem;
            scanf("%d", &elem);
            a = inserir(a, elem);
        }
        else
        {
            int elem;
            scanf("%d", &elem);
            a = remover(a, elem);
        }

        scanf("%d",&op);
    }


    printf("Em largura: ");
    imprime_largura(a);

    printf("\nPre ordem: ");
    preordem(a);

    printf("\nEm ordem: ");
    emordem(a);

    printf("\nPos ordem: ");
    posordem(a);

    return 0;


}