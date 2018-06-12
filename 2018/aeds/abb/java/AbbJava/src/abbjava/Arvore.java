package abbjava;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author daniel.conrado
 */
public class Arvore {
    
    public class No {
        int chave;
        No esq;
        No dir;
    }
    
    private No raiz;
    
    public void inserir(int chave) {
        if (raiz == null) {
            No novo = new No();
            novo.chave = chave;
            raiz = novo;
        } else {
            No aux = raiz;
            while (true) { // repete até encontrar o lugar
                if (chave < aux.chave) { // a chave deve ir à esquerda
                    if (aux.esq == null) {
                        No novo = new No();
                        novo.chave = chave;
                        aux.esq = novo;
                        break;
                    } else {
                        aux = aux.esq;
                    }
                } else { // a chave deve ir à direita do nó
                    if (aux.dir == null) {
                        No novo = new No();
                        novo.chave = chave;
                        aux.dir = novo;
                        break;
                    } else {
                        aux = aux.dir;
                    }                    
                }
            }
        }
        
    }
    
    private void imprimirPreOrdem(No no) {
        if (no != null) {
            System.out.printf("%d ", no.chave);
            imprimirPreOrdem(no.esq);
            imprimirPreOrdem(no.dir);
        }
    }
    
    public void imprimirPreOrdem() {
        imprimirPreOrdem(raiz);
    }
    
    private void imprimirEmOrdem(No no) {
        if (no != null) {
            imprimirEmOrdem(no.esq);
            System.out.printf("%d ", no.chave);
            imprimirEmOrdem(no.dir);
        }
    }
    
    public void imprimirEmOrdem() {
        imprimirEmOrdem(raiz);
    }
    
    public No minimo() {
        No aux = raiz;
        if (aux != null) {
            while (aux.esq != null)
                aux = aux.esq;
        }
        return aux;
    }
    
    public No procurar(int chave) {
        No aux = raiz;
        while (aux != null) {
            if (chave == aux.chave)
                return aux;
            else if (chave < aux.chave)
                aux = aux.esq;
            else
                aux = aux.dir;
        }
        return null;
    }
}
