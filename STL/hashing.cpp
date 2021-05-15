//Espalhamento (hashing)

//h(chave) = chave % 10 -> 5

#include <stdio.h>
#define TAM 10

int tabela[TAM];

int preenche(){
	int i;
	for(i = 0; i < TAM; i++){
		tabela[i] = -1;
	}
}

void mostra(){
	int i;
	for (int i = 0; i < TAM; ++i){
		printf("%.d - %.d\n", i, tabela[i]);
	}
}

int espalha(int chave){
	return chave % TAM;
}

int reespalha(int pos){
	return (pos + 1) % TAM;
}

void insere(int chave){
	int cont = 0;
	int pos;
	
	pos = espalha(chave);

	while(tabela[pos] != -1 && cont != TAM){
		pos = reespalha(pos);
		cont++;
	}
	if(cont != TAM){
		tabela[pos] = chave;
	} else {
		printf("NAO HA ESPACO");
	}
}

void busca(int chave){
	int pos;
	int cont = 0;

	pos = espalha(chave);

	while(tabela[pos] != chave && cont != TAM && tabela[pos] != -1){
		pos = reespalha(pos);
		cont++;
	}

	if(tabela[pos] == -1 || cont != TAM){
		printf("Nao achei.\n");
	} else {
		printf("Esta na posicao %d\n", pos);
	}
}

int main(){
	preenche();
	insere(5);
	insere(4);
	insere(34);
	insere(245);
	insere(564);
	insere(12);
	insere(542);

	busca(4);
	busca(3);
	busca(245);
	mostra();

}