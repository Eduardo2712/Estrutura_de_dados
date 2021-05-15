#include<ctime>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<conio.h>

using namespace std;

const int TAM = 90000;
int vetor[TAM];

void cria()
{
    int i;
    for(i=0; i<TAM; i++)
    {
        vetor[i]=rand();
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

 main()
{
    cria();
    clock_t tempo1, tempo2;
    int n;
    tempo1 = clock();
    bubbleSort();
    tempo2 = clock()-tempo1;
    printf("%f\n",(float) tempo2/CLOCKS_PER_SEC);
}
