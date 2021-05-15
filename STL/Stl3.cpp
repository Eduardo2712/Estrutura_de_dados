#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

list<int> lista;
list<int> :: iterator it;

int main()
{
    lista.push_back(40);
    lista.push_back(10);
    lista.push_back(30);
    lista.push_back(20);
    lista.push_back(50);
    it = lista.begin();
    it++;
    it++;
    lista.insert(it,15);
    for(it=lista.begin(); it!=lista.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    it = find(lista.begin(), lista.end(),40);
    if(it==lista.end())
    {
        cout << "Nao achei!!!" << endl;
    }
    else
    {
        cout << "Achei!!!" << endl;
    }
    lista.sort();
    it=lista.begin();
    lista.erase(it);
    lista.clear();
    if(lista.empty())
    {
        cout << "Lista vazia";
    }
}
