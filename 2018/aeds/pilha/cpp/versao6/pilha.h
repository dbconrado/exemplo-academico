#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

template <class T>
class Pilha
{
private:
    int tamanho;
    T *vetor;
    int topo = -1;
public:
    Pilha(int n);
    ~Pilha();
    bool cheia();
    bool vazia();
    void push(T &e);
    T &pop();
};

template <class T>
Pilha<T>::Pilha(int n)
{
    tamanho = n;
    vetor = new T [tamanho];
}

template <class T>
Pilha<T>::~Pilha()
{
    delete vetor;
}

template <class T>
bool Pilha<T>::vazia()
{
    return (topo == -1);
}

template <class T>
bool Pilha<T>::cheia()
{
    return (topo == tamanho-1);
}

template <class T>
void Pilha<T>::push(T &e)
{
    if (!cheia())
        vetor[++topo] = e;
    else
        throw "Pilha cheia";
}

template <class T>
T &Pilha<T>::pop()
{
    if (!vazia())
        return vetor[topo--];
    else
        throw "Pilha vazia";
}

#endif // PILHA_H_INCLUDED
