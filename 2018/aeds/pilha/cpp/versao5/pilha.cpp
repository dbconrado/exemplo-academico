/*

   Implementação da classe Pilha
   definida em pilha.h

*/

#include "pilha.h"

Pilha::Pilha(int tam_pilha)
{
    n = tam_pilha;
    vetor = new int[n]; // cria dinamicamente o vetor
}

Pilha::~Pilha()
{
    delete vetor; // em c++, ocorreu um new, deve ocorrer um delete
}

bool Pilha::vazia()
{
   return (topo == -1);
}

bool Pilha::cheia()
{
   return (topo == n-1);
}

void Pilha::push(int e)
{
   if (!cheia())
      vetor[++topo] = e;
   else
      throw "Pilha cheia (stack overflow)";
}

int Pilha::pop()
{
   if (!vazia())
      return vetor[topo--];
   else
      throw "Pilha vazia (stack underflow)";
}
