#include<iostream>
#include<stdlib.h>

using namespace std;

const int TAM=10;

 int fila[TAM];
 int inicio=0;
 int fim=0;
 int cont=0;
 int i,j;

void insereFila(int valor)
{
   if(cont==TAM)
   {
       cout << "\nFila Cheia!!!";
       return;
   }
   fila[fim]=valor;
   if(fim==TAM-1)
   {
       fim=0;
   }
   else
   {
       fim++;
   }
   cont++;
}

void vazia()
{
    if(cont==0)
    {
        cout << "Fila Vazia!!!";
        return;
    }
}

void removeFila()
{
    vazia();
    if(inicio==0)
    {
        inicio=inicio+1;
        cont=cont-1;
    }
    else
    {
        inicio=inicio-1;
        cont=cont-1;
    }
}

void inicioFila()
{
    vazia();
    cout << "\n" << fila[inicio];
}

void imprime()
{
    vazia();
    i=inicio;
    for(j=0; j<cont; j++)
    {
        cout << "" << fila[i];
        if(i==TAM-1)
        {
            i=0;
        }
        else
        {
            i++;
        }
    }
}

main()
{
    insereFila(8);
    insereFila(80);
    insereFila(70);
    removeFila();
    imprime();
}
