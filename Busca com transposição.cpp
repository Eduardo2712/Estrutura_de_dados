#include<cstdlib>
#include<iostream>

using namespace std;

const int TAM=10;

int cont=0;
int vetor[TAM];

void gerar()
{
    for(int i=0; i<TAM; i++)
    {
        vetor[i]=rand();
        cont++;
    }
}
void imprime()
{
    int i;
    for(i=0; i<TAM; i++)
    {
        cout << "" << vetor[i] << " ";
    }
    cout << endl;
}
void busca(int valor)
{

    int i;
    for(i=0; i<TAM; i++)
    {
        if(vetor[i]==valor)
        {

            if(i==0)
            {
                return;
            }
            else
            {
                int aux;
                aux=vetor[i-1];
                vetor[i-1]=vetor[i];
                vetor[i]=aux;
                return;
            }
        }
    }
}
main()
{
    gerar();
    imprime();
    busca(6);
    imprime();
}
