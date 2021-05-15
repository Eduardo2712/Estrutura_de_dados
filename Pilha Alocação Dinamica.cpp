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
    struct no *aux;         // Cria um ponteiro auxiliar de struct
    aux=new(struct no);     // AUX recebe a localização na memória de uma nova struct no
    aux->dados=valor;       // Passagem do valor passado por parametro
    aux->prox=topo;         // Passagem do endereço da struct nova
    topo=aux;               // Topo recebe o endereço da nova struct criada
}

void vazia()
{
    if(topo==NULL)
    {
        cout << "Pilha vazia!!!";
        return;
    }
}

void pop()
{
    vazia();
    struct no *aux;         // Criação de um ponteiro de struct aux
    aux=topo;               // Aux recebe a localização de topo
    topo=topo->prox;        // Topo recebe o endereço de seu anterior
    delete(aux);            // Ponteiro aux é deletado
}

int topoPilha()
{
    vazia();
    return topo->dados;
}

void imprime()
{
    vazia();
    struct no *aux;         // Criação de um ponteiro de struct
    aux=topo;               // Aux recebe o endereço do topo
    while(aux!=NULL)  // While que para quando achar o último elemento da pilha
    {
        cout << "" << aux->dados << " ";    // Imprime os elementos
        aux=aux->prox;      // Aux recebe o endereço do elemento anterior na pilha
    }
}

main()
{
    push(58);
    push(3);
    push(45);
    imprime();
}
