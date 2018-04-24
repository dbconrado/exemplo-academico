#include <iostream>

using namespace std;

/*
VERSÃO 2
Implementação da Pilha utilizando uma struct.
Mais versátil que a VERSÃO 1 pois permite
manipular mais de uma pilha.

Por ser uma struct, cada pilha carrega em si
seus elementos e seu controle (a.k.a. a variável topo).

Detalhe de implementação:
perceba que todos os procedimentos (vazia, cheia, push e pop)
recebem a pilha por referência, utilizando ponteiro.
Pense: por quê?

*/

#define TAM_PILHA 10

struct str_pilha
{
    int vetor[TAM_PILHA];
    int topo = -1;
};

bool vazia(str_pilha* p)
{
    return p->topo == -1;
}

bool cheia(str_pilha* p)
{
    return p->topo == TAM_PILHA-1;
}

void push(str_pilha* p, int e)
{
    if (!cheia(p))
        p->vetor[++p->topo] = e;
}

int pop(str_pilha* p)
{
    if (!vazia(p))
        return p->vetor[p->topo--];
}

int main()
{
    str_pilha minha_pilha;

    cout << "Empilhando 4, 5, 6" << endl;
    push(&minha_pilha, 4);
    push(&minha_pilha, 5);
    push(&minha_pilha, 6);

    cout << "Desempilhando..." << endl;
    while (!vazia(&minha_pilha))
        cout << pop(&minha_pilha) << endl;

    return 0;
}
