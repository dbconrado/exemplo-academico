#include <iostream>

using namespace std;

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

void testeVersao2()
{

}
