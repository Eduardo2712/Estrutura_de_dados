#include<iostream>
#include<cstdlib>

using namespace std;

const int TAM=10;

int vertices[TAM];
int cont=0;

struct no
{
    int destino;
    struct no *prox;
};
struct no *arestas[TAM];

void funcaoNull()
{
    int n;
    for(n=0; n<TAM; n++)
    {
        arestas[n]->prox=NULL;
    }
}

void insereVertice(int valor)
{
    int n;
    if(cont==TAM)
    {
        cout << "Vetor cheio" << endl;
        return;
    }
    for(n=0; n<cont; n++)
    {
        if(vertices[n]==valor)
        {
            cout << "Existe vertice igual!!!" << endl;
            return;
        }
    }
    vertices[cont]=valor;
    cout << "Vertice inserido com sucesso!!!" << endl;
    cont++;
}

void insereAresta(int origem, int destino)
{
    int n,oExiste=-1,dExiste=-1;
    for(n=0; n<cont; n++)
    {
        if(vertices[n]==origem)
        {
            cout << "Origem existe!!!"<< endl;
            oExiste=n;
        }
        if(vertices[n]==destino)
        {
            cout << "Destino existe!!!"<< endl;
            dExiste=n;
        }
    }
    if(oExiste==-1 || dExiste==-1)
    {
        cout << "Vertices nao existem!!!"<< endl;
        return;
    }
    struct no *atual, *anterior, *aux;
    atual=arestas[oExiste];
    while(atual!=NULL)
    {
        if(destino==atual->destino)
        {
            cout << "Aresta repetida!!!" << endl;
            return;
        }
        anterior=atual;
        atual=atual->prox;
    }
    aux=new(struct no);
    aux->destino=destino;
    aux->prox=NULL;
    if(arestas[oExiste]==NULL)
    {
        arestas[oExiste]=aux;
    }
    else
    {
        anterior->prox=aux;
    }
}

void removeAresta(int origem, int destino)
{
    int n,oExiste=-1,dExiste=-1;
    for(n=0; n<cont; n++)
    {
        if(vertices[n]==origem)
        {
            cout << "Origem existe!!!"<< endl;
            oExiste=n;
        }
        if(vertices[n]==destino)
        {
            cout << "Destino existe!!!"<< endl;
            dExiste=n;
        }
    }
    if(oExiste==-1 || dExiste==-1)
    {
        cout << "Vertices nao existem!!!"<< endl;
        return;
    }
    struct no *aux;
    aux=arestas[oExiste];
    while(aux!=NULL)
    {
        if(aux->destino==destino)
        {
            arestas[oExiste]=arestas[oExiste]->prox;
            delete(aux);
            cout << "Aresta removida!!!" << endl;
            return;
        }
        aux=aux->prox;
    }
    cout << "Aresta nao existe!!!" << endl;
}

void haAresta(int origem, int destino)
{
    int n,oExiste=-1,dExiste=-1;
    for(n=0; n<cont; n++)
    {
        if(vertices[n]==origem)
        {
            cout << "Origem existe!!!"<< endl;
            oExiste=n;
        }
        if(vertices[n]==destino)
        {
            cout << "Destino existe!!!"<< endl;
            dExiste=n;
        }
    }
    if(oExiste==-1 || dExiste==-1)
    {
        cout << "Vertices nao existem!!!"<< endl;
        return;
    }
    struct no *aux;
    aux=arestas[oExiste];
    while(aux!=NULL)
    {
        if(aux->destino==destino)
        {
            cout << "Existe uma aresta entre <" << vertices[oExiste] << "," << aux->destino << ">" << endl;
            return;
        }
        aux=aux->prox;
    }
    cout << "Aresta nao existe!!!" << endl;
}

void imprimeGrafo()
{
    if(cont==0)
    {
        cout << "Grafo nao existe!!!"<< endl;
        return;
    }
    int n,m;
    for(n=0; n<cont; n++)
    {
        cout << endl;
        cout << "" << vertices[n] << " ";
        struct no *aux;
        aux=arestas[n];
        while(aux!=NULL)
        {
            cout << "<" << vertices[n] << "," << aux->destino << "> ";
            aux=aux->prox;
        }
    }
    cout << endl;
    cout << endl;
}

main()
{
    insereVertice(56);
    insereVertice(90);
    insereVertice(31);
    insereAresta(90, 56);
    insereAresta(56, 31);
    imprimeGrafo();
    removeAresta(90,56);
    imprimeGrafo();
    haAresta(56,31);
}
