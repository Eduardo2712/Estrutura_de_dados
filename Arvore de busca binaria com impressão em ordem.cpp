#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

using namespace std;

struct no
{
    char dado[50];
    struct no *esq;
    struct no *dir;
};
struct no *raiz=NULL;

void insere(char *palavra)
{
    struct no *atual;
    struct no *anterior;
    struct no *aux;
    aux=new(struct no);
    strcpy(aux->dado,palavra);
    aux->esq=NULL;
    aux->dir=NULL;
    atual=raiz;
    if(raiz==NULL)
    {
        raiz=aux;
        return;
    }
    while(atual!=NULL)
    {
        anterior=atual;
        if(strcmp(palavra,atual->dado)<0)
        {
            atual=atual->esq;
        }
        else
        {
            atual=atual->dir;
        }
    }
    if(strcmp(palavra,anterior->dado)<0)
    {
        anterior->esq=aux;
    }
    else
    {
        anterior->dir=aux;
    }
}
void em_ordem(struct no *atual)
{
    if(atual!=NULL)
    {
        em_ordem(atual->esq);
        cout << " " << atual->dado << " ";
        em_ordem(atual->dir);
    }
}


main()
{
    FILE *fp;
    char palavra[50];
    char letra;
    fp=fopen("texto.txt","r");
    if(fp==NULL)
    {
        cout << "Erro";
        return 0;
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s",palavra);
        insere(palavra);
    }
    em_ordem(raiz);
    fclose(fp);
}
