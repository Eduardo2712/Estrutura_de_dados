#include <clocale>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

#define TAM 10

int vetor[TAM];

int partitio(int p, int r){
    int piv = vetor[p];
    int i = p - 1;
    int j = r + 1;
    while(true){
        do{
            j = j - 1;
        } while(vetor[j] > piv);
        do{
            i = i + 1;
        } while(vetor[i] < piv);
        if(i < j){
            int aux;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        } else {
            return j;
        }
    }
}


void quick_sort(int p, int r){
    if(p < r){
        int q;
        q = partitio(p, r);
        quick_sort(p, q);
        quick_sort(q+1, r);
    }
}

//gerador de vetor randomico
void vetor_random(){
    int i;
    for(i = 0; i < TAM; i++){
        vetor[i] = rand();
    }
}

int main(){
    setlocale(LC_ALL, "");

    clock_t tempo1, tempo2;
    vetor_random();
    tempo1 = clock();

    quick_sort(0, TAM-1); // primeiro e ultimo elemento do vetor

    tempo2 = clock() - tempo1;
    cout << "Duração: " << tempo2/CLOCKS_PER_SEC << " segundos" << endl;
    for(int n=0; n<10; n++)
    {
        cout << "" << vetor[n] << endl;
    }
    return 0;
}
