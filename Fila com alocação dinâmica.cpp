#include<iostream>
#include<stdlib.h>

using namespace std;

struct no
{
    int n;
    struct no *prox;
};

struct no *inicio=NULL;
struct no *fim=NULL;

void insereFila(int valor)
{
    struct no *aux;
    aux=new(struct no);
    aux->n=valor;
    aux->prox=NULL;
    if(inicio==NULL)
    {
        inicio=aux;
        fim=aux;
    }
    else
    {
        fim->prox=aux;
        fim=aux;
    }
}
void filaVazia()
{
    if(inicio==NULL)
    {
        cout << "Fila vazia!!!";
        return;
    }
}
void removeFila()
{
    filaVazia();
    struct no *aux;
    aux=inicio;
    inicio=inicio->prox;
    delete (aux);

}
void inicioFila()
{
    filaVazia();
    cout << "" << inicio->n;
}

void imprimeFila()
{
    filaVazia();
    struct no *aux;
    aux=inicio;
    while(aux!=NULL)
    {
        cout << "" << aux->n;
        aux=aux->prox;
    }
}

main()
{
    insereFila(50);
    insereFila(64);
    insereFila(88);
    inicioFila();
    removeFila();
    imprimeFila();
}
