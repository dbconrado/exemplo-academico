#include <iostream>

using namespace std;

/*
VERSÃO 1
Implementação da Estrutura de Dados Pilha
utilizando um vetor global.

O topo sempre aponta para o último elemento
inserido na pilha. Quando não há nenhum elemento,
topo é -1.

DESVANTAGEM PRINCIPAL
* com esse código, só é possível trabalhar com
apenas UMA pilha.

*/

const int n = 10;
int vetor[n];
int topo = -1;

bool vazia()
{
    return topo == -1;
}

bool cheia()
{
    return topo == n-1;
}

void push(int e)
{
    if (!cheia())
        vetor[++topo] = e;
}

int pop()
{
    if (!vazia())
        return vetor[topo--];
}

int main()
{
    cout << "Empilhando 1, 2, 3" << endl;
    push(1);
    push(2);
    push(3);

    cout << "Desempilhando..." << endl;
    while (!vazia())
        cout << pop() << endl;

    return 0;
}
