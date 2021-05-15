#include<iostream>
#include<stdlib.h>

using namespace std;

const int TAM=50;

struct no
{
    char dados;
    struct no *prox;
};
struct no *topo=NULL;

int i=0;
char pilha[TAM];
char vetor[TAM];
char aux;

void push(char caracter)
{
    struct no *aux;
    aux=new(struct no);
    aux->dados=caracter;
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
    aux=topo;
    topo=topo->prox;
    delete(aux);
}


int topoPilha()
{
    vazia();
    return topo->dados;
}

void imprime()
{
    struct no *aux;
    aux=topo;
    while(aux!=NULL)
    {
        cout << "" << aux->dados;
        aux=aux->prox;
        pop();
    }
}

main()
{
    cout << "Digite a cadeia de caracteres: ";
    cin >> vetor;
    while(vetor[i]!='\0')
    {
        if(vetor[i]=='a' || vetor[i]=='e' || vetor[i]=='i' || vetor[i]=='o' || vetor[i]=='u')
        {
            imprime();
            cout << "" << vetor[i];
        }
        else
        {
            aux=vetor[i];
            push(aux);
        }
        i++;
    }
    imprime();
}
