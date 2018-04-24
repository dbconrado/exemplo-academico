#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define TAM_PILHA 10

class Pilha
{
private:
    int vetor[TAM_PILHA];
    int topo = -1;

public:
    bool vazia();
    bool cheia();
    void push(int e);
    int pop();
};

/* Detalhe de implementação:
   o código dos métodos está
   em pilha.cpp
*/

#endif // PILHA_H_INCLUDED
