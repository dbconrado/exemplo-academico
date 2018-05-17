#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

#include "../versao1/lista.h"
#include <string>

#define M 5

class TabelaHash
{
    Lista vetor[M];
    int h(int chave);

public:
    void inserir(int chave, string dado);
    string procurar(int chave);
};

int TabelaHash::h(int chave)
{
    return chave % M;
}

void TabelaHash::inserir(int chave, string dado)
{
    int slot = h(chave);
    vetor[slot].inserir(chave, dado);
}

string TabelaHash::procurar(int chave)
{
    int slot = h(chave);
    return vetor[slot].procurar(chave);
}
#endif // TABELAHASH_H_INCLUDED
