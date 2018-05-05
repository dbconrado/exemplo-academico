#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/**
   Esta é uma implementação de Lista Encadeada
   que utiliza struct.


    Uma lista encadeada é um conjunto de nós
    em que cada nó possui um ponteiro para o seu sucessor.
    Numa lista duplamente encadeada, cada nó possui também
    um ponteiro para seu predecessor.

    Definimos o nó como uma struct
*/

struct No
{
    int chave;
    No *proximo; // ponteiro para o próximo nó da lista
    No *anterior; // ponteiro para o nó anterior
};

/*
Opcionalmente, podemos definir uma outra struct
que define uma lista encadeada.
Neste caso, é uma struct com apenas um ponteiro
que aponta para a cabeça da lista
*/
struct Lista
{
    No *cabeca;
};

/*
Nem só de struct vivem os TADs, mas tambm
das operações que podem ser feitas com elas.
Aqui, segue algumas operações básicas que podem
ser aplicadas em uma lista */

/**
    Insere um nó na cabeça da lista

    @param l a lista onde o nó será inserido
    @param no o nó a ser inserido
*/
void inserirNo(Lista *l, No *no)
{
    no->proximo = l->cabeca;
    if (l->cabeca != nullptr)
        l->cabeca->anterior = no;
    l->cabeca = no;
    no->anterior = nullptr;
}

/**
    Procura e retorna o nó que possui a chave informada

    @param l a lista onde procurar o nó
    @param chave a chave do nó a ser procurado
    @return um ponteiro para o nó com a chave informada
    ou nullptr caso não exista tal nó na lista
*/
No *procurarNo(Lista *l, int chave)
{
    No *x = l->cabeca;
    while ((x != nullptr) && (x->chave != chave))
        x = x->proximo;
    return x;
}

/**
    Remove da lista o nó especificado.
    Veja que o parâmetro passado é um ponteiro
    para um nó e não uma chave.
    Assim, este procedimento de remoção
    tem complexidade temporal de O(1).
    Caso não se tenha acesso ao nó,
    será preciso procurá-lo pela chave e, portanto,
    pode-se usar o procedimento @link procurarNo @endlink.
    Tal procedimento, porém, possui complexidade
    temporal de O(n).

    @param l a lista cujo nó será removido
    @param no o nó a ser removido
*/
void removerNo(Lista *l, No *no)
{
    if (no->anterior != nullptr)
        no->anterior->proximo = no->proximo;
    else
        l->cabeca = no->proximo;
    if (no->proximo != nullptr)
        no->proximo->anterior = no->anterior;
}



#endif // LISTA_H_INCLUDED
