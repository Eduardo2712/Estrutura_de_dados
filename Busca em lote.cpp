#include<cstdlib>
#include<iostream>

const int TAM = 10;

using namespace std;

int vetor[TAM] = {1,2,3,4,5,6,7,8,9,10};
int lote[TAM-4] = {0,2,3,4,9,11};

void buscaLote()
{
    int i,j=0, numeroBuscas=TAM-4;
    for(i=0; i<numeroBuscas; i++)
    {
        while(j<TAM && lote[i]>vetor[j])
        {
            j++;
        }
        if(j<TAM && lote[i]==vetor[j])
        {
            cout << "Achou " << lote[i] << endl;
        }
        else
        {
            cout << "Nao achou " << lote[i] << endl;
        }
    }
}
main()
{
    buscaLote();
}
