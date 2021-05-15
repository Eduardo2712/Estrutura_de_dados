#include<cstdlib>
#include<iostream>

using namespace std;

const int TAM=10;

struct no
{
    int dado;
    struct no *esq;
    struct no *dir;
    int bal;
};
struct no* raiz, *raiz_avl;

int vetor[TAM];
int v[TAM];
int contArvoreB=0, contAVL=0, contSequencial=0, contBinaria=0;
int tamHeap;

void insere(int valor)
{

    struct no *atual, *aux;

    aux = new(struct no);
    aux->dado = valor;
    aux->esq = NULL;
    aux->dir = NULL;

    atual=raiz;

    if (atual==NULL)
    {
        raiz = aux;
        return;
    }

    while (1)
    {
        if (valor < atual->dado)
            if (atual->esq==NULL)
            {
                atual->esq=aux;
                return;
            }
            else atual=atual->esq;
        else if (atual->dir==NULL)
        {
            atual->dir=aux;
            return;
        }
        else atual=atual->dir;
    }
}
void buscaArvore(int valor)
{
    if(raiz==NULL)
    {
        cout << "Arvore vazia!!!"<< endl;
        return;
    }
    struct no *aux;
    aux=raiz;
    while(aux!=NULL)
    {
        contArvoreB++;
        if(aux->dado==valor)
        {
            cout << "\nAchei o valor"<< endl;
            return;
        }
        else
        {
            contArvoreB++;
            if(aux->dado>valor)
            {
                aux=aux->dir;

            }
            else
            {
                aux=aux->esq;
            }
        }
    }
    cout << "\nNao achei o valor"<< endl;
}
void buscaAVL(int valor)
{
    if(raiz_avl==NULL)
    {
        cout << "Arvore vazia!!!"<< endl;
        return;
    }
    struct no *aux;
    aux=raiz_avl;
    while(aux!=NULL)
    {
        contAVL++;
        if(aux->dado==valor)
        {
            cout << "\nAchei o valor" << endl;
            return;
        }
        else
        {
            contAVL++;
            if(aux->dado>valor)
            {
                aux=aux->dir;
            }
            else
            {
                aux=aux->esq;
            }
        }
    }
    cout << "\nNao achei o valor" << endl;
}
// Rotação para a esquerda
void esquerda(struct no *p)
{

    struct no *q, *hold;

    q = p->dir;
    hold = q->esq;
    q->esq = p;
    p->dir = hold;

}
//Rotação para a direita
void direita(struct no *p)
{

    struct no *q, *hold;

    q = p->esq;
    hold = q->dir;
    q->dir = p;
    p->esq = hold;

}

// Cria um no e preenche os membros
struct no *cria_no(int valor)
{
    struct no *aux = new (struct no);
    aux->dado=valor;
    aux->dir=NULL;
    aux->esq=NULL;
    aux->bal=0;
    return aux;
};

//Insere valor em uma árvore AVL
void insere_bal(int chave)
{
    struct no *pp=NULL, *p=raiz_avl, *pajovem=NULL, *ajovem=raiz_avl, *q, *filho;
    int imbal;
    if (p==NULL)               /* Arvore vazia */
    {
        raiz_avl = cria_no(chave);  /* Funcao para criacao de um novo no */
        return;
    }
    /* Insere chave e descobre ancestral mais jovem a ser desbalanceado */
    while (p!=NULL)
    {
        if (chave < p->dado)
            q = p->esq;
        else q = p->dir;
        if (q!=NULL)
            if (q->bal != 0)
            {
                pajovem=p;
                ajovem=q;
            }
        pp = p;
        p = q;
    }
    q = cria_no(chave);

    if (chave<pp->dado)
        pp->esq=q;
    else pp->dir=q;

    /* Balanceamento de todos os nós entre ajovem e q devem ser ajustados */
    if (chave<ajovem->dado)
        filho = ajovem->esq;
    else filho = ajovem->dir;
    p = filho;
    while (p!=q)
    {
        if (chave < p->dado)
        {
            p->bal=1;
            p=p->esq;
        }
        else
        {
            p->bal = -1;
            p=p->dir;
        }
    }

    if (chave<ajovem->dado)
        imbal = 1;
    else imbal = -1;

    if (ajovem->bal==0)        /*Não houve desbalanceamento */
    {
        ajovem->bal=imbal;
        return;
    }


    if (ajovem->bal!=imbal)     /*Não houve desbalanceamento */
    {
        ajovem->bal=0;
        return;
    }

    /* Houve desbalanceamento */
    if (filho->bal == imbal)
    {
        p=filho;
        if (imbal==1)        /* Faz rotação simples */
            direita(ajovem);
        else esquerda(ajovem);
        ajovem->bal=0;
        filho->bal=0;
    }
    else
    {
        if (imbal==1)  	  /*Faz rotação dupla */
        {
            p=filho->dir;
            esquerda(filho);
            ajovem->esq=p;
            direita(ajovem);
        }
        else
        {
            p=filho->esq;
            direita(filho);
            ajovem->dir=p;
            esquerda(ajovem);
        }
        if (p->bal==0)
        {
            ajovem->bal=0;
            filho->bal=0;
        }
        else
        {
            if (p->bal == imbal)
            {
                ajovem->bal = - imbal;
                filho->bal = 0;
            }
            else
            {
                ajovem->bal = 0;
                filho->bal = imbal;
            }
        }
        p->bal=0;
    }

    if (pajovem == NULL)  /* Ajusta ponteiro do pai do ancestral mais jovem */
        raiz_avl = p;
    else if (ajovem==pajovem->dir)
        pajovem->dir = p;
    else pajovem->esq = p;
    return;
}
void mergesort(int lo,int hi)
{
    int l;
    int h;
    int k;
    int mid;
    if (lo<hi)
    {
        mid=(lo+hi)/2;
        mergesort(lo,mid);
        mergesort(mid+1,hi);
        l=lo;
        h=mid+1;
        for(k=lo;k<=hi;k++)
        {
            if (l<=mid && (h>hi || vetor[l]<vetor[h]))
            {
                v[k] = vetor[l];
                l=l+1;
            }else
            {
                v[k]=vetor[h];
                h=h+1;
            }
        }
        for(k=lo;k<=hi;k++)
        {
            vetor[k]=v[k];
        }
    }
}
void binaria(int valor)
{
    int inicio=0, meio, fim=TAM-1;
    while(inicio<=fim)
    {
        meio=(inicio+fim)/2;
        contBinaria++;
        if(vetor[meio]==valor)
        {
            cout << "Valor encontrado!!!" << endl;
            return;
        }
        contBinaria++;
        if(vetor[meio]>valor)
        {
            fim=meio-1;
        }
        else
        {
            inicio=meio+1;
        }
    }
}
void sequencial(int valor)
{
    int i=0;
    while(i<TAM && vetor[i]<valor)
    {
        contSequencial++;
        if(vetor[i]==valor)
        {
            cout << "Achou!!!"<< endl;
            return;
        }
        i++;
    }
    cout << "Nao achou!!!"<< endl;
}
main()
{
    int i;
    int chave;
    for(i=0; i<10; i++)
    {
        vetor[i]=rand();
        insere(vetor[i]);
        insere_bal(vetor[i]);
    }
    cout << endl;
    mergesort(0,TAM-1);
    for(int h=0; h<TAM; h++)
    {
        cout << "" << vetor[h] << " ";
    }
    cout << endl;
    for(i=0; i<TAM; i++)
    {
        chave=rand();
        buscaArvore(chave);
        buscaAVL(chave);
        binaria(chave);
        sequencial(chave);
    }
    cout << "Arvore Binaria: " << (float)contArvoreB/TAM << endl;
    cout << "Arvore AVL: " << (float)contAVL/TAM << endl;
    cout << "Busca Binaria: " << (float)contBinaria/TAM << endl;
    cout << "Busca Sequencial: " << (float)contSequencial/TAM << endl;
}
