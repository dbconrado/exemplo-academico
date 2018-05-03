#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/*

IMPLEMENTAÇÃO DE LISTA DUPLAMENTE ENCADEADA.

*/

#include <string>

using namespace std;

class No
{
public:
    int chave;
    string dado; // exemplo de como seria um dado satélite
    No *anterior;
    No *proximo;

};

class Lista
{
private:
    No *cabeca;
    No *criarNo(int chave, string dado);

    No *_procurar(int chave);
    void _inserir(No *novo);
    void _remover(No *no);

public:
    Lista(); // construtor
    string procurar(int chave); // nesta implementação, retorna o dado satelite ao invés do No
    void inserir(int chave, string dado);
    void remover(int chave); // nesta implementação, a remoção se dá pela chave e, portanto, envolve buscar o nó primeiro
    string montarListaEmString();
};

// implementação em lista.cpp

#endif // LISTA_H_INCLUDED
