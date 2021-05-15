#include <stdio.h>
#include <time.h>
#include<iostream>
#include<cstdlib>
#include<conio.h>

#define TAM 10

using namespace std;


int vetor[TAM];
int v[TAM];


void gerador()
{
    int i;
    for(i=0; i<TAM; i++)
        vetor[i]=rand();
}

void mergesort(int lo,int hi)
{
    int l;
    int h;
    int k;
    int mid;
    if (lo<hi)
    {
        mid=(lo+hi)/2;
        mergesort(lo,mid);
        mergesort(mid+1,hi);
        l=lo;
        h=mid+1;
        for(k=lo;k<=hi;k++)
        {
            if (l<=mid && (h>hi || vetor[l]<vetor[h]))
            {
                v[k] = vetor[l];
                l=l+1;
            }else
            {
                v[k]=vetor[h];
                h=h+1;
            }
        }
        for(k=lo;k<=hi;k++)
        {
            vetor[k]=v[k];
        }
    }
}



main()
{
    gerador();
    clock_t tempo1,tempo2;
    tempo1=clock();
    mergesort(0,TAM-1);
    for(int h=0; h<TAM; h++)
    {
        cout << "" << vetor[h] << " ";
    }
    tempo2=clock()-tempo1;
    printf("\n\tMerge sort\n\n");
    printf("\t%f\n\n",(float)tempo2/CLOCKS_PER_SEC);




}
