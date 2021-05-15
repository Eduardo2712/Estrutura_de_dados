//Eduardo Manoel de Lara
//Matheus Goulart

#include<cstdlib>
#include<iostream>

using namespace std;

const int TAM = 10;

struct no
{
    int dado;
    struct no *prox;
};
struct no *tabela[TAM];

int espalha(int chave)
{
    return chave%TAM;
}

void inicia()
{
    for(int i=0; i<TAM; i++)
    {
        tabela[i]=NULL;
    }
}

void insere(int chave)
{
    int pos;
    struct no *atual, *anterior, *novo;
    pos=espalha(chave);
    atual=tabela[pos];
    while(atual!=NULL)
    {
        if(atual->dado==chave)
        {
            cout << "Valor repetido";
            return;
        }
        anterior=atual;
        atual=atual->prox;
    }
    novo=new(struct no);
    novo->dado=chave;
    novo->prox=NULL;
    if(tabela[pos]!=NULL)
    {
        anterior->prox=novo;
    }
    else
    {
        tabela[pos]=novo;
    }
}

void busca(int chave)
{
    struct no *aux;
    int pos = espalha(chave);
    aux=tabela[pos];
    while(aux!=NULL)
    {
        if(aux->dado==chave)
        {
            cout << "Chave existe";
            return;
        }
        aux=aux->prox;
    }
    cout << "Chave nao encontrada";
}

void imprime()
{
    int i=0;
    struct no *atual;
    while(i<TAM)
    {
        atual = tabela[i];
        cout << "| " << i << " | ";
        while(atual!=NULL)
        {
            cout << "" << atual -> dado << " ";
            atual = atual ->prox;
        }
        cout << endl;
        i++;
    }
}

main()
{
    inicia();
    insere(55);
    insere(62);
    insere(75);
    insere(95);
    insere(15);
    insere(955);
    insere(5);
    imprime();
}
