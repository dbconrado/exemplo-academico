#include <iostream>
#include "pilha.h"

using namespace std;

/*
VERSÃO 3

Implementação da Pilha utilizando classe.
Normalmente, classes são implementadas em dois arquivos:
- um arquivo .h contendo a definição da classe apenas
- um arquivo .cpp que implementa a classe definida no arquivo .h

Veja a implementação em pilha.h e pilha.cpp

*/

int main()
{
    Pilha minha_pilha;

    cout << "Empilhando 7, 8, 9" << endl;
    minha_pilha.push(7);
    minha_pilha.push(8);
    minha_pilha.push(9);

    /*
        Membros privados não são acessíveis
        fora dos métodos da classe.

        A linha abaixo tenta acessar o vetor do objeto
        minha_pilha mas não consegue.
    */
    //cout << minha_pilha.vetor[2] << endl;

    cout << "Desempilhando..." << endl;

    while (!minha_pilha.vazia())
        cout << minha_pilha.pop() << endl;

    return 0;
}
