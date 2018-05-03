#include "fila.h"

// Implementação das definições de fila.h

void Fila::enfileirar(int elemento)
{
    elementos[cauda] = elemento;
    cauda += 1;
    if (cauda == TAM_VETOR)
        cauda = 0;
}

int Fila::desenfileirar()
{
    int elemento = elementos[cabeca];
    cabeca += 1;
    if (cabeca == TAM_VETOR)
        cabeca = 0;
    return elemento;
}
