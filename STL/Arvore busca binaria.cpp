#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

set<int> conjunto;
set<int> :: iterator it;

int main()
{
    conjunto.insert(40);
    conjunto.insert(10);
    conjunto.insert(30);
    conjunto.insert(20);
    conjunto.insert(50);
    for(it=conjunto.begin(); it!=conjunto.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    it = conjunto.find(40);
    if(it==conjunto.end())
    {
        cout << "Nao Achou";
    }
    else
    {
        cout << "Achou";
    }
    cout << endl;
}
