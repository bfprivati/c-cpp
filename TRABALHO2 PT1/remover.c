#include <stdio.h>
#include <stdlib.h>


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


Arv* arv_cria(int dado, Arv *esq, Arv *dir){
    Arv* p=(Arv*)malloc(sizeof(Arv));
    p->elem = dado;
    p->esq = esq;
    p->dir = dir;
    return p;
}


Arv* inserir(Arv* raiz, int elem){
   if (raiz == NULL){
      return arv_cria(elem,NULL,NULL);
   }
   else{
      if(elem < raiz->elem)
          raiz->esq = inserir(raiz->esq, elem);
      else
          raiz->dir = inserir(raiz->dir, elem);
   }
   return raiz;

}

Arv* busca_menor(Arv* raiz){
    if(raiz->esq == NULL)
        return raiz;
    else
        busca_menor(raiz->esq);
}


Arv* remover(Arv* raiz, int elem){
    Arv *aux, *menor;
    if(raiz == NULL){
        return NULL;
    }

    if(raiz->elem == elem){
        if(raiz->dir == NULL && raiz->esq == NULL){  //NÓ FOLHA
            free(raiz);
            return NULL;
        }
        else if(raiz->dir == NULL || raiz->esq == NULL){ //NÓ COM 1 FILHO
            aux = raiz;
            free(raiz);
            if(aux->dir == NULL)
                return aux->esq;
            else //if(aux->esq == NULL)
                return aux->dir; 
            //free(raiz);
        }
        else if(raiz->dir != NULL && raiz->esq != NULL){ //NÓ COM 2 FILHOS
            aux = raiz->dir;
            menor = busca_menor(raiz->dir);
            raiz->elem = menor->elem;
            raiz->dir = remover(raiz->dir, menor->elem);
            
            return raiz;
        }
    }
    else {
        if(elem < raiz->elem)
            raiz->esq = remover(raiz->esq, elem);
        else
            raiz->dir = remover(raiz->dir, elem);
        
    }
    return raiz;
}



int main (){

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

    printf("Pre ordem: ");
    preordem(a);

    printf("\nEm ordem: ");
    emordem(a);

    printf("\nPos ordem: ");
    posordem(a);

    return 0;


}