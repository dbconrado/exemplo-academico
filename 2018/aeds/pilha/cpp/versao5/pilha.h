#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

class Pilha
{
private:
    int n;
    int *vetor;
    int topo = -1;

public:
    Pilha(int tam_pilha);
    ~Pilha();
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
