/*

   Implementação da classe Pilha
   definida em pilha.h

*/

#include "pilha.h"

bool Pilha::vazia()
{
   return (topo == -1);
}

bool Pilha::cheia()
{
   return (topo == TAM_PILHA-1);
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
