#include<iostream>
#include<cstdlib>

const int TAM = 20;

int visita[TAM];
int vertices[TAM];
int adj[TAM][TAM];
int fila[TAM];
int inicio=0;
int fim=0;
int cont=0;

using namespace std;

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
            return;
        }
    }
    vertices[cont]=valor;
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
    if(oExiste==-1 || dExiste==-1)
    {
        cout << "Vertices nao existem!!!"<< endl;
        return;
    }
    adj[oExiste][dExiste]=1;
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
    if(oExiste==-1 || dExiste==-1)
    {
        cout << "Vertices nao existem!!!"<< endl;
        return;
    }
    if(adj[oExiste][dExiste]==0)
    {
        cout << "Aresta nao existe!!!"<< endl;
        return;
    }
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
    if(oExiste==-1 || dExiste==-1)
    {
        cout << "Vertices nao existem!!!"<< endl;
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
bool filaVazia()
{
    if(cont==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void filaCheia()
{
    if(cont==TAM)
    {
        cout << "Fila cheia!!!";
        return;
    }
}
void insereFila(int valor)
{
    filaCheia();
    if(fim==TAM)
    {
        fim=0;
        fila[fim]=valor;
    }
    else
    {
        fila[fim]=valor;
        fim++;
    }

    cont++;
}
int removeFila()
{
    int aux;
    aux=fila[inicio];
    if(inicio==TAM-1)
    {
        inicio=0;
    }
    else
    {
        inicio++;
    }
    cont--;
    return aux;
}
void bfs(int inicial)
{
    int v,a;
    for(v=0; v<cont; v++)
    {
        visita[v]=0;
    }
    visita[inicial]=1;
    cout << "" << vertices[inicial] << endl;
    insereFila(inicial);
    while(!filaVazia())
    {
        v=removeFila();
        for(a=0; a<cont; a++)
        {
            if(adj[v][a]==1 && visita[a]==0)
            {
                cout << "" << vertices[a] << endl;
                visita[a]=1;
                insereFila(a);
            }
        }
    }
}
main()
{
    insereVertice(1);
    insereVertice(2);
    insereVertice(3);
    insereVertice(4);
    insereVertice(5);
    insereVertice(0);
    insereAresta(0, 1);
    insereAresta(1, 0);
    insereAresta(1, 4);
    insereAresta(4, 1);
    insereAresta(0, 2);
    insereAresta(2, 0);
    insereAresta(2, 3);
    insereAresta(3, 2);
    insereAresta(2, 5);
    insereAresta(5, 2);
    bfs(0);
}
