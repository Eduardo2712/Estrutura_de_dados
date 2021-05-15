#include"stdio.h"
#include"queue"
#include"iostream"
#include"stack"
#include"vector"

using namespace std;
priority_queue<int, vector<int>, greater<int> > filap;

queue<int> fila;
stack<int> pilha;
vector<int> vetor;

int main(){

pilha.push(10);
pilha.push(100);
pilha.push(50);
pilha.push(20);

fila.push(10);
fila.push(100);
fila.push(50);
fila.push(20);

filap.push(10);
filap.push(100);
filap.push(50);
filap.push(20);

printf("Tamanho da pilha %d\n", pilha.size());
printf("Topo da pilha %d\n", pilha.top());
printf("\n");
printf("Tamanho da fila %d\n", fila.size());
printf("Topo da fila %d\n", fila.front());
printf("\n");
printf("Tamanho da filap %d\n", filap.size());
printf("Topo da filap %d\n", filap.top());

pilha.pop();
pilha.pop();

fila.pop();
fila.pop();

filap.pop();
filap.pop();

printf("\n\nDepois da remocao\n");
printf("Tamanho da pilha %d\n", pilha.size());
printf("Topo da pilha %d\n", pilha.top());
printf("\n");
printf("Tamanho da fila %d\n", fila.size());
printf("Topo da fila %d\n", fila.front());
printf("\n");
printf("Tamanho da filap %d\n", filap.size());
printf("Topo da filap %d\n", filap.top());

pilha.pop();
pilha.pop();

fila.pop();
fila.pop();

filap.pop();
filap.pop();

pilha.empty()? printf("Pilha vazia\n") : printf("Nao ta vazia\n");
fila.empty()? printf("fila vazia\n") : printf("Nao ta vazia\n");
filap.empty()? printf("filap vazia\n") : printf("Nao ta vazia\n");


vetor.push_back(100);
vetor.push_back(50);

vetor[0] = 1;
vetor[2] = 5;

printf("\n");]


}
