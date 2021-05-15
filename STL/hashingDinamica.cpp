#include <stdio.h>
#include <stdlib.h>
#define TAM 10

struct no {
	int dado;
	struct no *prox;
};


struct no *tabela[TAM];

void preenche(){
	int i;
	for (i = 0; i < TAM; i++) {
		tabela[i] = NULL;
	}
}

int espalha(int chave){
	return chave % TAM;
}

void insere(int chave){
	int aux;
	struct no *atual, *anterior, *novo;
	aux = espalha(chave);
	atual = tabela[aux];

	while(atual != NULL && atual->dado != chave){
		anterior = atual;
		atual = atual->prox;
	}

	if(atual != NULL){
		printf("Valor repetido\n");
		return;
	}

	novo = new(struct no);
	novo->dado = chave;
	novo->prox = NULL;

	if(tabela[aux] != NULL){
		anterior -> prox = novo;
	} else {
		tabela[aux] = novo;
	}

}

void busca(int valor){
	int aux;
	struct no *atual = NULL;

	aux = espalha(valor);
	atual = tabela[aux];

	while(atual != NULL){
		if(atual->dado == valor){
			printf("Achei (%d)\n", valor);
			return;
		}
		atual = atual->prox;
	}
	printf("Nao achei (%d)\n", valor);
}

void imprime(){
	int i;
	struct no *atual;
	for(i = 0; i < TAM; i++){
		printf("Tabela[%d]\n", i);
		atual = tabela[i];
		while(atual != NULL){
			printf(" { %d } ", atual->dado);
			atual = atual->prox;
		}
		printf("\n");
	}
}

int main(){
	preenche();

	insere(42);
	insere(32);
	insere(52);
	insere(562);

	imprime();

	busca(34);
	busca(52);
	
}

