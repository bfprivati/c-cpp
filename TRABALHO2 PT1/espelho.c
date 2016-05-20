#include <stdio.h>
#include <stdlib.h>
#define MAX 100


typedef struct arv
{
    int elem;
    struct arv *esq;
    struct arv *dir;
} Arv;




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


Arv* remover(Arv* raiz, int elem){

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





Arv* troca_filhos(Arv *raiz){
    Arv *aux = NULL;
    if(raiz ==  NULL){
        //printf("Arvore Vazia!\n");
        //return raiz;
    }
    else{
        troca_filhos(raiz->esq);
        troca_filhos(raiz->dir);
           
        aux = raiz->esq;
        raiz->esq = raiz->dir;
        raiz->dir = aux;
    }
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

    a = troca_filhos(a);

    printf("Pre ordem: ");
    preordem(a);

    printf("\nEm ordem: ");
    emordem(a);

    printf("\nPos ordem: ");
    posordem(a);

    return 0;


}