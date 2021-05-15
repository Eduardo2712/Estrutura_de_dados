#include<iostream>
#include<cstdlib>

using namespace std;

const int TAM=10;

int vetor[TAM];

void completa()
{
    for(int j=0; j<TAM; j++)
    {
        vetor[j]=-1;
    }
}
int espalha(int chave)
{
    return chave%TAM;
}
int reespalha(int pos)
{
    return (pos+1)%TAM;
}
void insere(int chave)
{
    int pos;
    pos=espalha(chave);
    if(vetor[pos]==-1)
    {
        cout << "Inserido!!!";
        vetor[pos]=chave;
        cout << endl;
        return;
    }
    else
    {
        while(vetor[pos]!=-1)
        {
            pos=reespalha(pos);
        }
        vetor[pos]=chave;
        cout << "Inserido!!!";
        cout << endl;
    }

}
void busca(int chave)
{
    for(int i=0; i<TAM; i++)
    {
        if(vetor[i]==chave)
        {
            cout << "Encontrado!!!";
            cout << endl;
            return;
        }
    }
}
void imprime()
{
    for(int l=0; l<TAM; l++)
    {
        cout << "pos " << l << " " << vetor[l];
        cout << endl;
    }
}
main()
{
    completa();
    insere(55);
    insere(62);
    insere(75);
    insere(95);
    insere(15);
    insere(955);
    insere(5);
    imprime();
}
