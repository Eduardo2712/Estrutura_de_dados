#include<cstdlib>
#include<iostream>

using namespace std;

const int TAM=10;

int cont=0;
int vetor[TAM];

void gerar()
{
    for(int i=0; i<TAM-1; i++)
    {
        vetor[i]=rand();
        cont++;
    }
}

void busca(int valor)
{
    int i;
    vetor[5]=3;
    vetor[cont]=valor;
    for(i=0; i<cont; i++)
    {
        if(vetor[i]==valor)
        {
            cout << "Valor encontrado!!!";
            return;
        }
    }
    cout << "Sentinela encontrado " << vetor[i] << endl;
}

main()
{
    gerar();
    busca(3);
}
