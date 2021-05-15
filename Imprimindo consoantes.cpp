#include<iostream>
#include<stdlib.h>

using namespace std;

const int TAM=50;

int topo=-1;
int i=0;
char pilha[TAM];
char vetor[TAM];
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


int topoPilha()
{
    vazia();
    return pilha[topo];
}

void imprime()
{
    while(pilha[topo]!='\0')
    {
        cout << "" << pilha[topo];
        topo=topo-1;
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
