#include<cstdlib>
#include<iostream>

const int TAM = 10;

using namespace std;

int vetor[TAM] = {1,2,3,4,5,6,7,8,9,10};

void binaria(int valor)
{
    int inicio=0, meio=0, fim=TAM-1;
    while(meio<TAM-1)
    {
        meio=(inicio+fim)/2;
        if(vetor[meio]==valor)
        {
            cout << "Valor encontrado!!!" << endl;
            return;
        }
        else
        {
            if(vetor[meio]>valor)
            {
                fim=meio;
            }
            if(vetor[meio]<valor)
            {
                inicio=meio;
            }
        }
    }
}
main()
{
    binaria(4);
}
