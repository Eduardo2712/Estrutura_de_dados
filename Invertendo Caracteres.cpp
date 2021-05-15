#include<iostream>
#include<stdlib.h>

using namespace std;

const int TAM=50;

int topo=-1;
char vetor[TAM];
char pilha[TAM];
int i=0;
char aux;

void push(char caracter)
{
    topo=topo+1;
    pilha[topo]=caracter;
}

void vazia()
{
    if(topo==-1)
    {
        cout << "Pilha vazia";
        return;
    }
}

void pop()
{
    vazia();
    topo=topo-1;
}

void topoPilha()
{
    cout << "" << pilha[topo];
}

void imprime()
{
    vazia();
    while(pilha[topo]!='\0')
    {
        cout << pilha[topo];
        topo=topo-1;
    }
}
main()
{
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
