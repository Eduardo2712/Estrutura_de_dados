#include<iostream>
#include<stdlib.h>

using namespace std;

const int TAM = 5;

int fila[TAM];
int inicio=0;
int fim=0;
int cont=0;

void filaCheia()
{
    if(cont==TAM)
    {
        cout << "Fila cheia!!!";
        return;
    }
}
void filaVazia()
{
    if(cont==0)
    {
        cout << "Fila vazia!!!";
        return;
    }
}
void insereFila(int valor)
{
    filaCheia();
    if(fim==TAM)
    {
        fim=0;
        fila[fim]=valor;
    }
    else
    {
        fila[fim]=valor;
        fim++;
    }
    cont++;
}
void removeFila()
{
    filaVazia();
    if(inicio==TAM-1)
    {
        inicio=0;
    }
    else
    {
        inicio++;
    }

    cont--;
}
void inicioFila()
{
    filaVazia();
    cout << "\n" << fila[inicio];
}
void imprimeFila()
{
    int i,j;
    filaVazia();
    j=inicio;
    for(i=cont; i>0; i--)
    {
        if(j==TAM-1 && i!=0)
        {
            cout << "" << fila[j] << " ";
            j=0;
        }
        else
        {
            cout << "" << fila[j] << " ";
            j++;
        }
    }
}
main()
{
    insereFila(10);
    insereFila(20);
    insereFila(8);
    insereFila(5);
    removeFila();
    insereFila(6);
    insereFila(88);
    removeFila();
    removeFila();
    removeFila();
    removeFila();
    insereFila(77);
    imprimeFila();
}
