#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<cstdio>
#include<ctime>

using namespace std;

const int TAM = 12;

int vetor[TAM] = {9, 27, 14, 6, 2, 8, 9, 17, 25, 17, 15, 6};

void gerar()
{
    for(int i=0; i<TAM; i++)
    {
        vetor[i]=rand();
    }
}
void insertion()
{
    int atual = 0;
    int  j;
    for (int i = 0; i < TAM; i++)
    {
        atual = vetor[i];
        j = i - 1;
        while ((j >= 0) && (atual < vetor[j]))
        {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = atual;
        for(int i=0; i<TAM; i++)
        {
            cout << "" << vetor[i]<< " ";
        }
        cout << endl;
    }
}

main()
{
    clock_t tempo1,tempo2;
    tempo1 = clock();
    insertion();
    tempo2 = clock() - tempo1;
    printf("\n%f", (float) tempo2/CLOCKS_PER_SEC);
}
