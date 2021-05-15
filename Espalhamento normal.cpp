//Eduardo Manoel de Lara
//Matheus Goulart

#include<iostream>
#include<cstdlib>

using namespace std;

const int TAM=10;
int cont=0;

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
    if(cont==TAM)
    {
        cout << "Vetor cheio!!!";
        cout << endl;
        return;
    }
    int pos;
    pos=espalha(chave);
    if(vetor[pos]==-1)
    {
        cout << "Inserido!!!";
        vetor[pos]=chave;
        cout << endl;
        cont++;
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
        cont++;
    }

}
void busca(int chave)
{
    int contB=0;
    int pos;
    pos=espalha(chave);
    while(vetor[pos]!=-1)
    {
        if(contB==TAM)
        {
            cout << "Valor nao existe!!!";
            cout << endl;
            return;
        }
        if(vetor[pos]==chave)
        {
            cout << "Numero " << vetor[pos] << " encontrado!!!";
            cout << endl;
            return;
        }
        pos=reespalha(pos);
        contB++;
    }
    cout << "Valor nao existe!!!";
    cout << endl;
}
void imprime()
{
    for(int l=0; l<TAM; l++)
    {
        if(vetor[l]!=-1)
        {
            cout << "|" << l << "| " << vetor[l];
            cout << endl;
        }
        else
        {
            cout << "|" << l << "|";
            cout << endl;
        }
    }
}
main()
{
    completa();
    insere(95);
    insere(15);
    insere(955);
    insere(5);
    insere(62);
    insere(75);
    insere(9);
    insere(67);
    insere(99);
    insere(45);
    imprime();
    busca(3);
}
