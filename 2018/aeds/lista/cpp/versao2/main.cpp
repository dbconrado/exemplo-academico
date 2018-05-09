#include <iostream>
#include "lista.h"

using namespace std;

void exibirLista(Lista *l)
{
    cout << "[";
    No* x = l->cabeca;
    if (x != nullptr)
    {
        cout << x->chave;
        x = x->proximo;
        while (x != nullptr)
        {
            cout << " -> " << x->chave;
            x = x->proximo;
        }
    }
    cout << "]";
}

int main()
{
    cout << "Criando uma lista encadeada e encadeando uns numeros" << endl;
    Lista minha_lista;
    minha_lista.cabeca = nullptr;

    No no1, no2, no3;
    no1.chave = 1;
    no2.chave = 2;
    no3.chave = 3;

    cout << "lista vazia: ";
    exibirLista(&minha_lista);

    cout << endl;
    cout << "inserindo três nós" << endl;
    inserirNo(&minha_lista, &no1);
    inserirNo(&minha_lista, &no2);
    inserirNo(&minha_lista, &no3);

    cout << "lista agora: ";
    exibirLista(&minha_lista);

    cout << endl;

    cout << "Removendo o segundo nó" << endl;

    removerNo(&minha_lista, &no2);

    cout << endl;
    cout << "Lista agora: ";
    exibirLista(&minha_lista);

    cout << endl;

    return 0;
}
