#include <stdlib.h>
#include <iostream>
#include <clocale>

const int TAM=50;

using namespace std;

main()
{
    setlocale(LC_ALL,"");
    int i=0;
    char vetor[TAM];
    cout << "\nDigite a expressão: ";
    cin >> vetor[TAM];
    while (vetor[i]!= '\0'){
        if (vetor[i]=='('){
                Push('(');
            }
    }
}
