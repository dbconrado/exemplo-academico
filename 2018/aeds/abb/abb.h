/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   abb.h
 * Author: daniel.conrado
 *
 * Created on 5 de Junho de 2018, 11:06
 */

#ifndef ABB_H
#define ABB_H

#include <iostream>
using namespace std;


struct No {
    int chave;
    No *esq;
    No *dir;
    No *pai;
};

struct Arvore {
    No *raiz;
};


No *buscar(Arvore *arvore, int chave) {
    No *no = arvore->raiz;
    while (no != nullptr && no->chave != chave) {
        if (chave < no->chave)
            no = no->esq;
        else
            no = no->dir;
    }
    return no;
}

No *criarNo(int chave) {
    No *novo = new No;
    novo->chave = chave;
    novo->esq = nullptr;
    novo->dir = nullptr;
    novo->pai = nullptr;
    return novo;
}

void inserir(Arvore *arvore, int chave) {
    No *novo = criarNo(chave);

    if (arvore->raiz == nullptr)
        arvore->raiz = novo;
    else {

        No *no = arvore->raiz;
        while (true) {
            if (chave < no->chave) {
                if (no->esq == nullptr) {
                    no->esq = novo;
                    novo->pai = no;
                    break;
                } else {
                    no = no->esq;
                }
            } else {
                if (no->dir == nullptr) {
                    no->dir = novo;
                    novo->pai = no;
                    break;
                } else {
                    no = no->dir;
                }
            }
        }

    }
}

void imprimir_preordem(No *raiz) {
    if (raiz != nullptr) {
        cout << raiz->chave << " ";
        imprimir_preordem(raiz->esq);
        imprimir_preordem(raiz->dir);
    }
}

Arvore *criarArvore() {
    Arvore *arvore = new Arvore;
    arvore->raiz = nullptr;
    return arvore;
}

#endif /* ABB_H */

