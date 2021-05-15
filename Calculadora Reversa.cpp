#include<iostream>
#include<stdlib.h>

using namespace std;

const int TAM = 50;
float pilha[TAM];
int topo=-1;
int i;
char vetor[TAM];
float n1, n2;
char aux;


void push()
{
    topo=topo+1;
    pilha[topo]=(aux-48);
}

void pop()
{
    topo=topo-1;
}

int topoPilha()
{
    return pilha[topo];
}

main()
{
    cout << "\nDigite a expressao: ";
    cin >> vetor;
    for(i=0; vetor[i]!= '\0'; i++)
    {
        if(vetor[i]>=48 && vetor[i]<=57)
        {
            aux=vetor[i];
            push();
        }
        if(vetor[i]=='+')
        {
            n1=topoPilha();
            pop();
            n2=topoPilha();
            pop();
            cout << "" << n1+n2;
        }
        if(vetor[i]=='-')
        {
            n1=topoPilha();
            pop();
            n2=topoPilha();
            pop();
            cout << "" << n1-n2;
        }
        if(vetor[i]=='*')
        {
            n1=topoPilha();
            pop();
            n2=topoPilha();
            pop();
            cout << "" << n1*n2;
        }
        if(vetor[i]=='/')
        {
            n1=topoPilha();
            pop();
            n2=topoPilha();
            pop();
            cout << "" << n1/n2;
        }

    }
}
