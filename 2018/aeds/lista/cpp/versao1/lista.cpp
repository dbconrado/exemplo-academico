#include "lista.h"
#include <string>
#include <sstream>

using namespace std;

Lista::Lista() {
    cabeca = nullptr;
}

No *Lista::criarNo(int chave, string dado)
{
    No *novo = new No();
    novo->chave = chave;
    novo->dado = dado;

    return novo;
}

No *Lista::_procurar(int chave)
{
    No *x = cabeca;
    while ((x != nullptr) && (x->chave != chave))
        x = x->proximo;

    return x;
}

string Lista::procurar(int chave)
{
    No *no = _procurar(chave);
    if (no != nullptr)
        return no->dado;
    else
        return "Não encontrado";
}

void Lista::_inserir(No *novo)
{
    novo->proximo = cabeca;
    if (cabeca != nullptr)
        cabeca->anterior = novo;
    cabeca = novo;
    novo->anterior = nullptr;
}

void Lista::inserir(int chave, string dado)
{
    No *novo = criarNo(chave, dado);
    _inserir(novo);
}

void Lista::_remover(No *no)
{
    if (no->anterior != nullptr)
        no->anterior->proximo = no->proximo;
    else
        cabeca = no->proximo;

    if (no->proximo != nullptr)
        no->proximo->anterior = no->anterior;
}

void Lista::remover(int chave)
{
    // primeiro, procura o nó com a chave
    No *no = _procurar(chave);
    if (no != nullptr) // encontrou o nó
    {
        _remover(no);
    }
}

string Lista::montarListaEmString()
{
    string resultado = "[\n";
    No *x = cabeca;
    while (x != nullptr)
    {
        resultado += "  ";
        stringstream ss;
        ss << x->chave;
        resultado += ss.str();
        resultado += " => ";
        resultado += x->dado;
        resultado += "\n";

        x = x->proximo;
    }
    resultado += "]\n";
    return resultado;
}
