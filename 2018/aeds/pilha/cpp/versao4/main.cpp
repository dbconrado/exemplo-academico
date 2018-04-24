#include <iostream>
#include "pilha.h"

using namespace std;

/*
   VERSÃO 4
   Pilha implementada em classe.

   DIFERENÇA PARA A VERSÃO 3:
      Na versão 4, a pilha lança uma exceção
      quando se tenta empilhar mais elementos
      que o suportado, ou quando se tenta
      desempilhar uma pilha vazia.
*/

int main()
{
   Pilha pilha;

   cout << "Empilhando até estourar!" << endl;
   try
   {
      int i = 1;
      while (true)
      {
         cout << "Empilhando " << i << endl;
         pilha.push(i++);
      }
   }
   catch (const char* ex)
   {
      cout << "OOOPS! " << ex << endl;
   }

    return 0;
}
