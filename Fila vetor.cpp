#include<iostream>
#include<stdlib.h>

using namespace std;

const int TAM = 10;

int fila[TAM];
int inicio=0;
int fim=0;
int contador=0;

void filaCheia()
{
    if(contador==TAM)
    {
        cout << "Fila Cheia!!!";
        return;
    }
}

void insereFila(int n)
{
    filaCheia();
    fila[fim]=n;
    if(fim==TAM-1)
    {
        fim=0;
    }
    else
    {
        fim++;
    }
}

void vazia()
{
    if(contador==0)
    {
        cout << "Fila vazia!!!";
        return;
    }
}

void removeFila()
{
    vazia();
    if(inicio==0)
    {
        inicio=TAM-1;
    }
    else
    {
        inicio--;
    }
    contador--;
}

void inicioFila()
{
    vazia();
    cout << fila[inicio] << " ";
}

void imprime()
{

}
