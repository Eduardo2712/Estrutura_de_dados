#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<stdio.h>
#include<time.h>

const int TAM=10;

int vetor[TAM];
int tamHeap;

void heapify(int i)
{
    int l, r, max, aux;
    l=2*i+1;
    r=2*i+2;
    if(l<tamHeap && vetor[l]>vetor[i])
    {
        max = l;
    }
    else
    {
        max = i;
    }
    if(r<tamHeap && vetor[r]>vetor[max])
    {
        max=r;
    }
    if(max!=i)
    {
        aux=vetor[i];
        vetor[i]=vetor[max];
        vetor[max]=aux;
        heapify(max);
    }
}

void buildHeap()
{
    tamHeap=TAM;
    int j;
    for(j=(TAM/2)-1; j>=0; j--)
    {
        heapify(j);
    }
}

void heapSort()
{
    buildHeap();
    int k, aux;
    for(k=TAM-1; k>=1; k--)
    {
        aux=vetor[0];
        vetor[0]=vetor[k];
        vetor[k]=aux;
        tamHeap=tamHeap-1;
        heapify(0);
    }
}

void gerar()
{
    for(int i=0; i<TAM; i++)
    {
        vetor[i]=rand();
    }
}

main()
{
    gerar();
    clock_t tempo1,tempo2;
    tempo1 = clock();
    heapSort();
    tempo2 = clock() - tempo1;
    printf("%f", (float) tempo2/CLOCKS_PER_SEC);
    for(int n=0; n<TAM; n++)
    {
        printf("\n%d", vetor[n]);
    }
}
