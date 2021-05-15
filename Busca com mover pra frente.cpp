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
void busca(int valor)
{
    int i;
    for(i=0; i<TAM; i++)
    {
        if(vetor[i]==valor)
        {
            int aux;
            aux=vetor[i];
            while(i!=0)
            {
                vetor[i]=vetor[i-1];
                i--;
            }
            vetor[i]=aux;
            return;
        }
    }
    cout << "Valor nao encontrado!!!";
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
main()
{
    gerar();
    imprime();
    busca(3);
    imprime();
}
