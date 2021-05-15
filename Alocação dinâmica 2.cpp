#include<iostream>
#include<stdlib.h>

using namespace std;

const int TAM = 5;

struct no
{
    int dado;
    struct no *prox;
};
struct no *topo=NULL;

push(int valor)
{
    struct no *aux;
    aux=new(struct no);
    topo->dado = valor
    topo->prox = topo;
    topo=aux;

}
