#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

using namespace std;




int vetor[TAM];

void gerador()
{
    int i;
    for(i=0;i<TAM;i++)
    {
        vetor[i]=rand();
    }

}

void insertion()
{
    int k;
    int x;
    int i;
    int aux;
    bool found;

    for(k=1;k<=TAM-1;k++){
        x=vetor[k];
        i=k-1;
        found=false;
        while(not found && i>=0){
            if (vetor[i]>x){
                vetor[i+1]=vetor[i];
                aux=vetor[i+1];
                i=i-1;
            }else{
                found=true;
            }
        }
    }



}


main()
{
    gerador();
    clock_t tempo1,tempo2;
    tempo1=clock();
    insertion();
    tempo2=clock()-tempo1;
    printf("\n\tInsertion sort\n\n");
    printf("\t%f\n\n",(float)tempo2/CLOCKS_PER_SEC);
    for(int n=0; n<10; n++)
    {
        printf("\n%d",vetor[n]);
    }



}
