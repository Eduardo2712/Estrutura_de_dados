#include<stdlib.h>
#include<iostream>
#include<conio.h>

/*

Cores:
    0 = Preto          8 = Cinza
    1 = Azul           9 = Azul claro
    2 = Verde        10 = Verde claro
    3 = Verde-água   11 = Verde-água claro
    4 = Vermelho     12 = Vermelho claro
    5 = Roxo         13 = Lilás
    6 = Amarelo      14 = Amarelo claro
    7 = Branco       15 = Branco brilhante
*/



using namespace std;

const int TAM=50;

struct no
{
    int dado;
    int usado;
};
struct no arvore[TAM];

void vazia()
{
    if(arvore[0].usado==0)
    {
        cout << "Arvore vazia!!!";
        return;
    }
}

void insere(int valor)
{
    int atual=0;
    while(atual<TAM && arvore[atual].usado!=0)
    {
        if(valor<arvore[atual].dado)
        {
            atual=2*atual+1;
        }
        else
        {
            atual=2*atual+2;
        }
    }
    if(atual<TAM)
    {
        arvore[atual].dado=valor;
        arvore[atual].usado=1;
    }
    else
    {
        cout << "Elemento nao foi inserido";
    }
}
void em_ordem(int atual)
{
    vazia();
    if(atual<TAM && arvore[atual].usado!=0)
    {
        em_ordem(2*atual+1);
        cout << " " << arvore[atual].dado << " ";
        em_ordem(2*atual+2);
    }
}
void busca(int valor)
{
    int atual=0;
    while(atual<TAM && arvore[atual].usado!=0)
    {
        if(valor<arvore[atual].dado)
        {
            atual=2*atual+1;
        }
        if(valor>arvore[atual].dado)
        {
            atual=2*atual+2;
        }
        if(valor==arvore[atual].dado)
        {
            cout << endl;
            cout << " " << arvore[atual].dado << endl;
            return;
        }
    }
}
void insereArvoreSemRepetidos(int valor)
{
    int atual=0;
    while(atual<TAM && arvore[atual].usado!=0)
    {
        if(arvore[atual].dado!=valor)
        {

            if(valor<arvore[atual].dado)
            {
                atual=2*atual+1;
            }
            else
            {
                atual=2*atual+2;
            }
        }
        else
        {
            cout << "Elemento igual";
            return;
        }
    }
    if(atual<TAM)
    {
        arvore[atual].dado=valor;
        arvore[atual].usado=1;
    }
    else
    {
        cout << "Elemento nao foi inserido";
    }
}

main()
{
    system("color 09");
    int atual=0;

}
