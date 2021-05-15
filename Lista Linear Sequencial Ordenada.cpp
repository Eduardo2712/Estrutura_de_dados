#include<stdlib.h>
#include<iostream>

using namespace std;

const int TAM = 5;

int lista[TAM];
int tamanho=0;
int i;
int j;

void listaCheia()
{
    if(tamanho==TAM)
    {
        cout << "Lista cheia!!!";
        return;
    }
}

void insereLista(int valor)
{
    listaCheia();
    for(i=tamanho; valor<lista[i-1] && i>0; i--)
    {
        lista[i]=lista[i-1];
    }
    lista[i]=valor;
    tamanho++;
}

void recuperaPosicao(int posicao)
{
    if(posicao>tamanho-1 || posicao<0)
    {
        cout << "Posicao invalida!!!";
        return;
    }
    else
    {
        cout << "" << lista[posicao];
    }
}

void removeLista(int posicao)
{
    if(posicao>tamanho || posicao<0)
    {
        cout << "Posicao invalida!!!";
        return;
    }
    else
    {
        for(i=tamanho-1; i<tamanho; i++)
        {
            lista[i-1]=lista[i];
        }
        tamanho--;
    }
}

void removeValor(int valor)
{
    for(i=0; i<tamanho && valor>=lista[i]; i++)
    {
        if(lista[i]==valor)
        {
            for(j=i; j<tamanho-1; j++)
            {
                lista[j]=lista[j+1];
            }
            tamanho--;
            return;
        }
    }
    cout << "Nao achei";
}

void imprime()
{
    if(tamanho==0)
    {
        cout << "Lista vazia!!!";
    }
    else
    {
        for(i=0; i<tamanho; i++)
        {
            cout << "" << lista[i] << " ";
        }
        cout << "\n";
    }
}

main()
{
    insereLista(50);
    insereLista(80);
    insereLista(71);
    insereLista(2);
    imprime();
    imprime();
}
