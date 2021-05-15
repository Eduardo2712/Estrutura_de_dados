#include <stdio.h>
#include <conio.h>
using namespace std;


#define TAM 10
int vetor[TAM];

void preencheVetor(){
    for(int i=0; i<TAM; i++){
        vetor[i]=-1;
    }
}

int espalha(int chave){
    return chave%TAM;
}

int reespalha(int pos){
    return (pos+1)%TAM;
}

void insere(int chave){
    int cont=0;
    int i = espalha(chave);
    if(vetor[i]==-1){
        vetor[i]=chave;
    }
    else{
        while(cont<TAM){
            i = reespalha(i);
            if(vetor[i] == -1){
                vetor[i] = chave;
                return;
            }
            cont++;
        }
    }
}

void busca(int chave){
    int cont=0;
    int i = espalha(chave);
    if(vetor[i]==chave){
        printf("elemento encontrado");
    }
    else{
        while(cont<TAM){
            i = reespalha(i);
            if(vetor[i] == chave){
                printf(" elemento encontrado");
                return;
            }
            cont++;
        }
    }
    printf("elemento nao encontrado ");
}

void imprime(){
    for(int i=0; i<TAM; i++){
        printf("%d ", vetor[i]);
    }
}

main(){
    preencheVetor();
    insere(14);
    insere(15);
    insere(24);
    imprime();
}
