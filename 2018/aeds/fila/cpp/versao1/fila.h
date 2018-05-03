#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define TAM_VETOR 10

/*

Implementação de uma Fila (FIFO)
utilizando um vetor de tamanho fixo.
VERSÃO 1

Na Fila, há dois controles:

- a cabeça da fila
- a cauda da fila

Quando um elemento é inserido, ele é
colocado na cauda da fila.
Quando um elemento é removido, ele é
retirado da cabeça da fila.

Para um vetor de n elementos, você
consegue armazenar até n-1 elementos na fila.

OBS: na versão 1, NÃO foi implementada
a lógica que impede o estouro (positivo e negativo) da fila.

*/

class Fila {
private:
    int elementos[TAM_VETOR];
    int cabeca = 0;
    int cauda = 0;
public:
    void enfileirar(int elemento);
    int desenfileirar();
};

// Implementação está em fila.cpp

#endif // FILA_H_INCLUDED
