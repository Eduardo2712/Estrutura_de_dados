#include<stdio.h>
#define TAM 10

struct no{
    int dado;
    struct no*prox;
};
struct no*tabela[TAM];
int espalha(int chave){
    return chave%TAM;
}
void inicia(){
    int i = 0;
    while(i<TAM){
        tabela[i] = NULL;
        i++;
    }
}
void insere (int valor){
    int pos;
    struct no * atual, *anterior, *novo;
    pos = espalha(valor);
    atual = tabela[pos];
    while(atual!= NULL){
        if(atual -> dado == valor){
            printf("Elemento repetido\n");
            return;
        }
        anterior = atual;
        atual = atual -> prox;
    }
    novo = new(struct no);
    novo -> dado = valor;
    novo -> prox = NULL;
    if(tabela[pos] != NULL){
        anterior -> prox = novo;
        printf("Elemento inserido\n");
        return;
    }
    tabela[pos] =  novo;
    printf("Elemento inserido\n");

}
void busca(int valor){
    int pos = espalha(valor);
    struct no * atual;
    atual = tabela[pos];
    while(atual!= NULL){
        if((atual -> dado) == valor){
            printf("Encontrado\n");
            return;
        }
        atual = atual->prox;
    }
    printf("Nao encontrado\n");
}
void imprime(){
    int i = 0;
    struct no * atual;
    while(i<TAM){
       atual = tabela[i];
       printf("|%d| ->", i);
       while(atual!= NULL){
        printf("[%d] ", atual-> dado);
        atual = atual-> prox;
       }
        printf("\n");
        i++;
    }
}
int main(){
    inicia();
    insere(14);
    insere(35);
    insere(4);
    insere(14);
    busca(4);
    busca(35);
    imprime();
    return  0;
}
