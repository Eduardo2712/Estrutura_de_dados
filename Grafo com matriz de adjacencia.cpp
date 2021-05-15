#include<cstdlib>
#include<iostream>

using namespace std;

const int TAM=10;

int vertices[TAM];
int adj[TAM][TAM];
int cont=0;

void zera()
{
    int n,m;
    for(n=0; n<TAM; n++)
    {
        for(m=0; m<TAM; m++)
        {
            adj[n][m]=0;
        }
    }
}

void insereVertice(int valor)
{
    int n;
    if(cont==TAM)
    {
        cout << "Vetor cheio!!!" << endl;
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
            oExiste=n;
        }
        if(vertices[n]==destino)
        {
            dExiste=n;
        }
    }
    if(oExiste==-1 && dExiste==-1)
    {
        cout << "Destino e origem nao existem!!!"<< endl;
        return;
    }
    if(oExiste==-1)
    {
        cout << "Origem nao existe!!!"<< endl;
        return;
    }
    if(dExiste==-1)
    {
        cout << "Destino nao existe!!!"<< endl;
        return;
    }
    if(adj[oExiste][dExiste]==1)
    {
        cout << "Aresta ja existe!!!"<< endl;
        return;
    }
    adj[oExiste][dExiste]=1;
    cout << "Aresta inserida!!!"<< endl;
}

void removeAresta(int origem, int destino)
{
    int n,oExiste=-1,dExiste=-1;
    for(n=0; n<cont; n++)
    {
        if(vertices[n]==origem)
        {
            oExiste=n;
        }
        if(vertices[n]==destino)
        {
            dExiste=n;
        }
    }
    if(oExiste==-1 && dExiste==-1)
    {
        cout << "Destino e origem nao existem!!!"<< endl;
        return;
    }
    if(oExiste==-1)
    {
        cout << "Origem nao existe!!!"<< endl;
        return;
    }
    if(dExiste==-1)
    {
        cout << "Destino nao existe!!!"<< endl;
        return;
    }
    if(adj[oExiste][dExiste]==0)
    {
        cout << "Aresta nao existe!!!"<< endl;
        return;
    }
    cout << "Aresta existe!!!"<< endl;
    adj[oExiste][dExiste]=0;
    cout << "Aresta removida!!!"<< endl;
}

void haAresta(int origem, int destino)
{
    int n,oExiste=-1,dExiste=-1;
    for(n=0; n<cont; n++)
    {
        if(vertices[n]==origem)
        {
            oExiste=n;
        }
        if(vertices[n]==destino)
        {
            dExiste=n;
        }
    }
    if(oExiste==-1 && dExiste==-1)
    {
        cout << "Destino e origem nao existem!!!"<< endl;
        return;
    }
    if(oExiste==-1)
    {
        cout << "Origem nao existe!!!"<< endl;
        return;
    }
    if(dExiste==-1)
    {
        cout << "Destino nao existe!!!"<< endl;
        return;
    }
    if(adj[oExiste][dExiste]==0)
    {
        cout << "Aresta nao existe!!!"<< endl;
        return;
    }
    cout << "Entre " << vertices[oExiste] << " e " << vertices[dExiste] << " existe uma aresta!!!"<< endl;
}

void imprimeGrafo()
{
    if(cont==0)
    {
        cout << "Grafo nao existe!!!"<< endl;
        return;
    }
    int n,m;
    cout << endl;
    for(n=0; n<cont; n++)
    {
        cout << "" << vertices[n];
        for(m=0; m<cont; m++)
        {
            if(adj[n][m]==1)
            {
                cout << " <" << vertices[n] << "," << vertices[m] << "> ";
            }
        }
        cout << endl;
    }
}

main()
{
    zera();
    insereVertice(63);
    insereVertice(55);
    insereVertice(13);
    insereVertice(88);
    insereVertice(4);
    insereAresta(55,63);
    insereAresta(63,55);
    insereAresta(13,88);
    insereAresta(88,4);
    insereAresta(4,88);
    insereAresta(4,13);
    insereAresta(13,63);
    insereAresta(63,4);
    imprimeGrafo();
}
