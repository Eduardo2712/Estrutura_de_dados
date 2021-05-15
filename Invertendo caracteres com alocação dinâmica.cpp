#include<iostream>
#include<stdlib.h>

using namespace std;

char vetor[50];

struct no
{
    char dado;
    struct no *prox;
};
struct no *topo=NULL;


void push(char caracter)
{
    struct no *aux;
    aux=new(struct no);
    aux->dado=caracter;
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
    struct no *aux;
    vazia();
    aux=topo;
    topo=topo->prox;
    delete(aux);
}

void topoPilha()
{
    cout << "" << topo->dado;
}

void imprime()
{
    struct no *aux;
    vazia();
    aux=topo;
    while(aux!=NULL)
    {
        cout << "" << aux->dado;
        aux=aux->prox;
    }
}
main()
{
    int i=0;
    char aux;
    cout << "Digite a cadeia de caracteres: ";
    cin >> vetor;
    while(vetor[i]!='\0')
    {
        aux=vetor[i];
        push(aux);
        i++;
    }
    imprime();
}
