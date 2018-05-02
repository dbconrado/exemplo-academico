#include <iostream>
#include "fila.h"

using namespace std;

int main()
{
    Fila minha_fila;

    for (int i = 1; i <= 9; i++)
    {
        cout << "Enfileirando " << i << endl;
        minha_fila.enfileirar(i);
    }

    cout << "..." << endl;

    for (int i = 1; i <= 3; i++)
        cout << "Desenfileirou " << minha_fila.desenfileirar() << endl;

    cout << "..." << endl;

    for (int i = 1; i <= 3; i++)
    {
        cout << "Enfileirando " << i << endl;
        minha_fila.enfileirar(i);
    }

    for (int i = 1; i <= 9; i++)
        cout << "Desenfileirou " << minha_fila.desenfileirar() << endl;

    return 0;
}
