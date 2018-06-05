/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: daniel.conrado
 *
 * Created on 5 de Junho de 2018, 11:05
 */

#include <cstdlib>
#include "abb.h"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    Arvore *arvore = criarArvore();

    inserir(arvore, 7);
    inserir(arvore, 5);
    inserir(arvore, 9);

    imprimir_preordem(arvore->raiz);

    No *no = buscar(arvore, 9);
    cout << no->chave;

    return 0;
}

