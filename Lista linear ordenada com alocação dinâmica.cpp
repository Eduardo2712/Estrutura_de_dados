#include<iostream>
#include<stdlib.h>

using namespace std;

struct no
{
    int dado;
    struct no *prox;
};
struct no *lista = NULL;

int n=-1;

void insereLista(int valor)
{
    struct no *atual;
    struct no *anterior;
    struct no *aux;
    aux=new(struct no);
    aux->dado=valor;
    atual=lista;
    while(atual!=NULL && atual->dado<valor)
    {
        anterior=atual;
        atual=atual->prox;
    }
    if(atual==lista)
    {
        aux->prox=atual;
        lista=aux;
    }
    else
    {
        aux->prox=atual;
        anterior->prox=aux;
    }
    n++;
}
void listaVazia()
{
    if(lista==NULL)
    {
        cout << "Lista vazia";
        return;
    }
}
void removeValor(int valor)
{
    listaVazia();
    struct no *atual;
    struct no *anterior;
    atual=lista;
    while(atual!=NULL && atual->dado<=valor)
    {
        if(atual->dado==valor)
        {
            if(atual==lista)
            {
                lista=lista->prox;
            }
            else
            {
                anterior->prox=atual->prox;
            }
            delete(atual);
            return;
        }
        anterior=atual;
        atual=atual->prox;
    }
    cout << "Valor nao encontrado";
}
void removeLista(int posicao)
{
    listaVazia();
    struct no *atual;
    struct no *anterior;
    atual=lista;
    if(posicao>n)
    {
        cout << "Posicao invalida";
    }
    while(cont!=n )
    {

    }
}
void imprime()
{
    listaVazia();
    struct no *atual;
    atual=lista;
    while(atual!=NULL)
    {
        cout << "" << atual->dado << " ";
        atual=atual->prox;
    }
}

main()
{
    insereLista(3);
    insereLista(7);
    insereLista(12);
    removeValor(30);
    imprime();
}
