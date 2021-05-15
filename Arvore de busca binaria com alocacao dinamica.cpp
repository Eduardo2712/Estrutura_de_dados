#include<iostream>
#include<stdlib.h>

using namespace std;

struct no
{
    int dado;
    struct no *esq;
    struct no *dir;
};
struct no *raiz=NULL;

void insere(int valor)
{
    struct no *atual;
    struct no *anterior;
    struct no *aux;
    aux=new(struct no);
    aux->dado=valor;
    aux->esq=NULL;
    aux->dir=NULL;
    atual=raiz;
    if(raiz==NULL)
    {
        raiz=aux;
        return;
    }
    while(atual!=NULL)
    {
        anterior=atual;
        if(valor<atual->dado)
        {
            atual=atual->esq;
        }
        else
        {
            atual=atual->dir;
        }
    }
    if(valor<anterior->dado)
    {
        anterior->esq=aux;
    }
    else
    {
        anterior->dir=aux;
    }
}
void em_ordem(struct no *atual)
{
    if(atual!=NULL)
    {
        em_ordem(atual->esq);
        cout << " " << atual->dado << " ";
        em_ordem(atual->dir);
    }
}
void buscaArvore(int valor)
{
    if(raiz==NULL)
    {
        cout << "Arvore vazia!!!";
        return;
    }
    struct no *aux;
    aux=raiz;
    while(aux!=NULL)
    {
        if(aux->dado==valor)
        {
            cout << "\nAchei o valor";
            return;
        }
        else
        {
            if(aux->dado>valor)
            {
                aux=aux->dir;
            }
            if(aux->dado<valor)
            {
                aux=aux->esq;
            }
        }
    }
    cout << "\nNao achei o valor";
}

main()
{
    insere(55);
    insere(2);
    insere(6);
    em_ordem(raiz);
    buscaArvore(0);
}
