#include <iostream>
#include "pilha.h"

using namespace std;

/*
    VERSÃO 5
    Implementando uma pilha usando classe,
    exceções, construtor e destrutor.

    A classe Pilha ficou ainda mais versátil.
    Agora, você pode criar pilhas com capacidades
    diferentes!
    Nas versões anteriores, todas as pilhas
    alojam no máximo 10 elementos.
    (Como foi definido pela diretiva TAM_PILHA)
*/

void empilharEternamente(Pilha *p)
{
    cout << "Empilhando ate estourar!" << endl;
    try
    {
        int i = 1;
        while (true)
        {
            cout << "Empilhando " << i << endl;
            p->push(i++);
        }
    }
    catch (const char* ex)
    {
        cout << "Oops! " << ex << endl;
    }
}

int main()
{
    cout << "Criando uma pilha de 5 elementos!" << endl;
    Pilha p1(5);

    empilharEternamente(&p1);

    cout << "Agora, mais uma pilha de 3 elementos!" << endl;
    Pilha p2(3);

    empilharEternamente(&p2);

    cout << "Desempilhando loucamente!" << endl;
    try
    {
        for (;;)
            cout << "Desempilhando " << p2.pop() << endl;
    }
    catch (const char* ex)
    {
        cout << "OOOOPS! " << ex << endl;
    }

    return 0;
}
