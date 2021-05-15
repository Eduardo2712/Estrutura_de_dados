#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>

const int TAM=10;
int vetor[TAM];

void selectionSort()
{
    int i;
    int aux;
    int current;
    int k;
    for(i=0; i<TAM-2; i++)
    {
        current = i;
        for(k=i+1; k<=TAM-1; k++)
        {
            if(vetor[current]>vetor[k])
            {
                current=k;
            }
        }
        aux=vetor[i];
        vetor[i]=vetor[current];
        vetor[current]=aux;
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
    selectionSort();
    tempo2 = clock() - tempo1;
    printf("%f", (float) tempo2/CLOCKS_PER_SEC);
    for(int n=0; n<TAM; n++)
    {
        printf("\n%d", vetor[n]);
    }
}
