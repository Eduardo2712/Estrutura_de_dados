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
void bubbleSort()
{
    int pass=1;
    int i;
    int aux;
    bool sorted=false;
    while(!sorted && pass<TAM)
    {
        sorted=true;
        for(i=0; i<=TAM-pass-1; i++)
        {
            if(vetor[i]>vetor[i+1])
            {
                aux=vetor[i];
                vetor[i]=vetor[i+1];
                vetor[i+1]=aux;
                sorted=false;
            }
        }
        pass=pass+1;
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
    bubbleSort();
    busca(3);
}
