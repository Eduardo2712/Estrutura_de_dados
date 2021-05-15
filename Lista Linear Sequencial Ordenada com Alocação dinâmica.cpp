#include<iostream>
#include<stdlib.h>

using namespace std;

struct no
{
    int dado;
    struct no *prox;
};
struct no *lista=NULL;

void insereLista(int valor)
{
    struct no *atual;
    struct no *anterior;
    struct no *aux;
    aux=new(struct no);
    aux->dado=valor;
    atual=lista;

}
