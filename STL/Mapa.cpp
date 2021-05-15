#include<iostream>
#include<map>
#include<string>

using namespace std;

map<int, string> mapa;
map<int, string> :: iterator it;

int main()
{
    mapa[10]="Batman";
    mapa[100]="Kakaroto";
    mapa[50]="Muralha";
    for(it=mapa.begin(); it!=mapa.end(); it++)
    {
        cout << it->first << " -> " << it->second << endl;
    }
    it = mapa.find(50);
    if(it==mapa.end())
    {
        cout << "" << "Nao achou";
    }
    else
    {
        cout << "" << "Achou " << it->second;
    }
    cout << endl;
}
