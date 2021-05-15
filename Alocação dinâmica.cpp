#include<iostream>
#include<stdlib.h>

using namespace std;

struct no
{
    int dados;
    struct no *prox;
};
struct no *topo=NULL;

void push(int valor)
{
    struct no *aux;
    aux=new(struct no);
    aux->dados=valor;
    aux->prox=topo;
    topo=aux;
}

void vazia()
{
    if(topo==NULL)
    {
        cout << "Pilha vazia";
        return;
    }
}

void pop()
{
    vazia();
    struct no *aux;
}
